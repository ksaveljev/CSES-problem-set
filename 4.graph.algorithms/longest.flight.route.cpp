#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9+5;

int main(void) {
    int n, m;

    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> distance(n, INF);
    vector<int> parent(n, -1);

    distance[0] = 0;

    int a, b;
    while (m--) {
        cin >> a >> b;
        -- a, --b;
        adj[a].push_back(b);
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, 0});

    while (!q.empty()) {
        auto [d, v] = q.top();
        q.pop();

        for (auto u: adj[v]) {
            if (d - 1 < distance[u]) {
                distance[u] = d - 1;
                parent[u] = v;
                q.push({distance[u], u});
            }
        }
    }

    if (distance[n-1] == INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;

        for (int x = n - 1; x != -1; x = parent[x]) {
            path.push_back(x);
        }

        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for (int i = 0; i < path.size(); i++) {
            if (i > 0) cout << " ";
            cout << path[i] + 1;
        }
        cout << endl;
    }

    return 0;
}
