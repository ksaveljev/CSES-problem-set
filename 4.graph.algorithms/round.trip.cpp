#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1e5;
int n, m;
vector<int> adj[maxN];
vector<int> color, parent;
int cycle_start, cycle_end;

bool dfs(int v, int p) {
    color[v] = 1;

    for (int u : adj[v]) {
        if (u == p) continue;

        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u, v)) {
                return true;
            }
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }

    color[v] = 2;
    return false;
}

int main(void) {
    cin >> n >> m;

    color.assign(n, 0);
    parent.assign(n, -1);

    int a, b;
    while (m--) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cycle_start = -1;

    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && dfs(i, parent[i]))
            break;
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);

        cout << cycle.size() << endl;
        for (int i = 0; i < cycle.size(); i++) {
            if (i > 0) cout << " ";
            cout << cycle[i] + 1;
        }
        cout << endl;
    }

    return 0;
}
