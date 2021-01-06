#include <iostream>
#include <vector>
#include <tuple>
#include <set>
using namespace std;

typedef long long ll;
const ll INF = 1e18+5;

void dfs(int i, set<int>& s, const vector<vector<int>>& adj) {
    s.insert(i);

    for (int v: adj[i]) {
        if (s.find(v) == s.end()) {
            dfs(v, s, adj);
        }
    }
}

int main(void) {
    int n, m;
    int a, b;
    ll x;

    cin >> n >> m;

    vector<tuple<int,int,ll>> edges;
    vector<vector<int>> adj(n);
    vector<vector<int>> adj2(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> x;
        --a, --b;
        edges.push_back({a, b, x});
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }

    vector<ll> dist(n);
    for (int i = 0; i < n; i++) {
        dist[i] = -INF;
    }

    dist[0] = 0;

    vector<int> changed;
    for (int i = 0; i < n; i++) {
        changed.clear();
        for (auto [a, b, x]: edges) {
            if (dist[a] + x > dist[b]) {
                changed.push_back(b);
                dist[b] = dist[a] + x;
            }
        }
    }

    if (changed.empty()) {
        cout << dist[n-1] << endl;
    } else {
        set<int> visited;
        dfs(0, visited, adj);
        set<int> visited2;
        dfs(n-1, visited2, adj2);

        bool ok = true;

        for (int v: changed) {
            if (visited.find(v) != visited.end() && visited2.find(v) != visited2.end()) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << dist[n-1] << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
