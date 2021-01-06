#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

typedef long long ll;
const ll INF = 1e18+5;

int main(void) {
    int n, m;
    cin >> n >> m;

    int a, b;
    ll c;
    vector<vector<pair<int,ll>>> adj(n);
    while (m--) {
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back({b,c});
    }

    vector<ll> dist(n, INF);
    vector<ll> disc(n, INF);

    dist[0] = 0;
    disc[0] = 0;

    priority_queue<tuple<ll,int,bool>, vector<tuple<ll,int,bool>>, greater<tuple<ll,int,bool>>> q;
    q.push({0,0,false});

    while (!q.empty()) {
        auto [d, v, f] = q.top();
        q.pop();

        if (f) {
            if (disc[v] < d) continue;
        } else {
            if (dist[v] < d) continue;
        }

        for (auto [u, c] : adj[v]) {
            if (f) {
                if (d + c < disc[u]) {
                    disc[u] = d + c;
                    q.push({disc[u], u, true});
                }
            } else {
                if (d + c < dist[u]) {
                    dist[u] = d + c;
                    q.push({dist[u], u, false});
                }
                if (d + c/2 < disc[u]) {
                    disc[u] = d + c/2;
                    q.push({disc[u], u, true});
                }
            }
        }
    }

    cout << disc[n-1] << endl;

    return 0;
}
