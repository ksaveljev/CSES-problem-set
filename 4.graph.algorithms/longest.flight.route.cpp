#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 1e9+7;
const int maxN = 1e5;
int n, m;
vector<int> parent(maxN, -1);
vector<int> adj[maxN];
int in[maxN];
vector<int> dist(maxN, -INF);

int main(void) {
    cin >> n >> m;

    int a, b;
    while (m--) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        in[b]++;
    }

    dist[0] = 0;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : adj[v]) {
            if (dist[v] + 1 > dist[u]) {
                dist[u] = dist[v] + 1;
                parent[u] = v;
            }
            in[u]--;
            if (in[u] == 0) q.push(u);
        }
    }

    if (dist[n-1] < 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> result;
        result.push_back(n-1);
        while (result.back() != 0) {
            result.push_back(parent[result.back()]);
        }
        reverse(result.begin(), result.end());
        cout << result.size() << endl;
        for (int& x : result) {
            cout << x+1 << " ";
        }
        cout << endl;
    }
}
