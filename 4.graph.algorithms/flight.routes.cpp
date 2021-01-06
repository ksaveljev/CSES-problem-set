#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1e18+5;

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int,ll>>> adj(n);
    vector<vector<ll>> dist(n, vector<ll>(k, INF));

    dist[0][0] = 0;

    int a, b;
    ll c;

    while (m--) {
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back({b, c});
    }

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    q.push({0, 0});

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();

        if (dist[cur.second][k-1] < cur.first) continue;

        for (auto [u, c]: adj[cur.second]) {
            if (c + cur.first < dist[u][k-1]) {
                dist[u][k-1] = c + cur.first;
                q.push({dist[u][k-1], u});
                sort(dist[u].begin(), dist[u].end());
            }
        }
    }

    for (int i = 0; i < k; i++) {
        if (i > 0) cout << " ";
        cout << dist[n-1][i];
    }
    cout << endl;

    return 0;
}
