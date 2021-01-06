#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxN = 1e5;
int n, m;
vector<int> adj[maxN];
int color[maxN];

bool ok = true;

void dfs(int i, int c = 0) {
    if (!ok) return;

    if (color[i] != -1) {
        if (color[i] ^ c) {
            ok = false;
        }
        return;
    }

    color[i] = c;
    for (int v : adj[i]) {
        dfs(v, c ^ 1);
    }
}

int main(void) {
    int a, b;

    cin >> n >> m;

    while (m--) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(color, -1, 4 * n);

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            dfs(i);
        }
    }

    if (!ok) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << color[i] + 1;
        }
        cout << endl;
    }

    return 0;
}
