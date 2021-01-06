#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

const ll INF = 1e18+5;

int main(void) {
    int n, m;

    cin >> n >> m;

    vector<vector<pair<int,ll>>> adj(n);
    vector<ll> distance(n);
    vector<bool> visited(n);

    for (int i = 0; i < n; i++)
        distance[i] = INF;

    distance[0] = 0;

    int a, b;
    ll c;
    while (m--) {
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back({b, c});
    }

    priority_queue<pair<ll,int>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();

        if (visited[v]) continue;
        visited[v] = true;

        for (auto [u, c]: adj[v]) {
            if (distance[v] + c < distance[u]) {
                distance[u] = distance[v] + c;
                pq.push({-distance[u], u});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << distance[i];
    }
    cout << endl;
}
