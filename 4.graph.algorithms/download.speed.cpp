#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

const ll INF = 1e18+7;
const int maxN = 500, maxM = 1e3;
int n, m;
vector<pair<int,int>> edges(2*maxM);
vector<int> adj[maxN];
ll capacity[2*maxM];

ll bfs(int source, int target, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<int,ll>> q;
    q.push({source, INF});
    while (!q.empty()) {
        auto [current, flow] = q.front();
        q.pop();

        for (int e: adj[current]) {
            int next = edges[e].first ^ edges[e].second ^ current;
            if (parent[next] == -1 && capacity[e]) {
                parent[next] = e;
                ll adjusted_flow = min(flow, capacity[e]);
                if (next == target) {
                    return adjusted_flow;
                }
                q.push({next, adjusted_flow});
            }
        }
    }
    return 0;
}

int main(void) {
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        --a, --b;
        edges[2*i] = {a, b};
        edges[2*i+1] = {b, a};
        adj[a].push_back(2*i);
        adj[b].push_back(2*i+1);
        capacity[2*i] = c;
    }

    ll result = 0;
    ll tmp;
    vector<int> parent(n);

    while ((tmp = bfs(0, n-1, parent))) {
        result += tmp;
        int current = n - 1;
        while (current != 0) {
            int e = parent[current];
            int previous = edges[e].first ^ edges[e].second ^ current;
            capacity[e] -= tmp;
            capacity[e^1] += tmp;
            current = previous;
        }
    }

    cout << result << endl;

    return 0;
}
