#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef unsigned long long ull;

const ull INF = 1e18+5;
const ull mod = 1e9+7;

int main(void) {
    int n, m;

    cin >> n >> m;

    vector<vector<pair<int,ull>>> adj(n);
    vector<ull> distance(n, INF);
    vector<ull> count(n);
    vector<ull> min_flights(n, INF);
    vector<ull> max_flights(n, 0);

    int a, b;
    ull c;
    while (m--) {
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back({b, c});
    }

    priority_queue<pair<ull,int>, vector<pair<ull,int>>, greater<pair<ull,int>>> q;
    q.push({0, 0});

    distance[0] = 0;
    count[0] = 1;
    min_flights[0] = 0;
    max_flights[0] = 0;

    while (!q.empty()) {
        auto [d, v] = q.top();
        q.pop();

        for (auto [u, c]: adj[v]) {
            if (d > distance[u]) {
                continue;
            } else if (d + c == distance[u]) {
                count[u] += count[v];
                count[u] %= mod;
                min_flights[u] = min(min_flights[u], min_flights[v] + 1);
                max_flights[u] = max(max_flights[u], max_flights[v] + 1);
            } else if (d + c < distance[u]) {
                distance[u] = d + c;
                q.push({distance[u], u});

                count[u] = count[v];
                min_flights[u] = min_flights[v] + 1;
                max_flights[u] = max_flights[v] + 1;
            }
        }
    }

    cout << distance[n-1] << " " << count[n-1] << " " << min_flights[n-1] << " " << max_flights[n-1] << endl;

    return 0;
}
