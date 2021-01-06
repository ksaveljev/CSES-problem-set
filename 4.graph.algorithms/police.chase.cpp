#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int maxN = 500, maxM = 1000, INF = 1e9+7;
int n, m;
vector<int> adj[maxN];
int capacity[maxN][maxN];
int visited[maxN];
vector<pair<int,int>> edges;

int bfs(int source, int target, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<int,int>> q;
    q.push({source, INF});
    while (!q.empty()) {
        auto [current, flow] = q.front();
        q.pop();

        for (int next: adj[current]) {
            if (parent[next] == -1 && capacity[current][next]) {
                parent[next] = current;
                int adjusted_flow = min(flow, capacity[current][next]);
                if (next == target)
                    return adjusted_flow;
                q.push({next, adjusted_flow});
            }
        }
    }
    return 0;
}

void dfs(int v) {
    visited[v] = 1;
    for (int u: adj[v]) {
        if (!visited[u] && capacity[v][u]) {
            dfs(u);
        }
    }
}

int main(void) {
    cin >> n >> m;

    int a, b;
    while (m--) {
        cin >> a >> b;
        --a, --b;
        edges.push_back({a, b});
        adj[a].push_back(b);
        adj[b].push_back(a);
        capacity[a][b] = 1;
        capacity[b][a] = 1;
    }

    int tmp;
    int cut = 0;
    vector<int> parent(n);
    while ((tmp = bfs(0, n-1, parent))) {
        cut += tmp;
        int current = n-1;
        while (current != 0) {
            int previous = parent[current];
            capacity[previous][current] -= tmp;
            capacity[current][previous] += tmp;
            current = previous;
        }
    }

    dfs(0);

    cout << cut << endl;
    for (auto [a, b]: edges) {
        if (visited[a] && !visited[b] && !capacity[a][b]) {
            cout << a + 1 << " " << b + 1 << endl;
        }
    }

    return 0;
}
