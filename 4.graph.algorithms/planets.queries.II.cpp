#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int nax = 2e5;
const int LOG = 19;
int n, q;

int parent[nax][LOG];
vector<int> depth(nax);
vector<bool> visited(nax);

void dfs(int v) {
    visited[v] = true;

    if (!visited[parent[v][0]]) {
        dfs(parent[v][0]);
    }

    depth[v] = depth[parent[v][0]] + 1;
}

int lift(int v, int k) {
    if (k <= 0) return v;

    for (int j = 0; j < LOG; j++) {
        if (k & (1<<j)) {
            v = parent[v][j];
        }
    }

    return v;
}

int main(void) {
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> parent[i][0];
        parent[i][0]--;
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    int a, b;
    while (q--) {
        cin >> a >> b;
        --a, --b;

        int c = lift(a, depth[a]);
        if (lift(a, depth[a] - depth[b]) == b) {
            cout << depth[a] - depth[b] << "\n";
        } else if (lift(c, depth[c] - depth[b]) == b) {
            cout << depth[a] + depth[c] - depth[b] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
