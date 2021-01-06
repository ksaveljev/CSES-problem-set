#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

typedef long long ll;
const ll INF = 1e18+5;

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,ll>> edges;

    int a, b;
    ll c;
    while (m--) {
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    vector<ll> dist(n+1, INF);
    vector<ll> p(n+1, -1);

    int x;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (int j = 0; j < edges.size(); j++) {
            auto [a, b, c] = edges[j];
            if (dist[a] + c < dist[b]) {
                dist[b] = max(-INF, dist[a] + c);
                p[b] = a;
                x = b;
            }
        }
    }

    if (x == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<int> path;

        int y = x;
        for (int i = 0; i < n; i++) {
            y = p[y];
        }

        for (int cur = y; ; cur = p[cur]) {
            path.push_back(cur);
            if (cur == y && path.size() > 1) {
                break;
            }
        }

        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++) {
            if (i > 0) cout << " ";
            cout << path[i];
        }
        cout << endl;
    }

    return 0;
}
