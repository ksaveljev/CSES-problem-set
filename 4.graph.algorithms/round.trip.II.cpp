#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;

    for (int u: adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
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

    adj.resize(n);

    color.assign(n, 0);
    parent.assign(n, -1);

    int a, b;
    while (m--) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
    }

    cycle_start = -1;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && dfs(i)) {
            break;
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << endl;
        for (int i = 0; i < cycle.size(); i++) {
            if (i > 0) cout << " ";
            cout << cycle[i] + 1;
        }
        cout << endl;
    }

    return 0;
}
