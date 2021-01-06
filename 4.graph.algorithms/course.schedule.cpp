#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> adj2;
vector<int> color;
int cycle_start;
vector<int> result;

void dfs2(int v) {
    for (int u: adj2[v]) {
        if (color[u] == 0) {
            dfs2(u);
        }
    }

    result.push_back(v);
    color[v] = 1;
}

bool dfs(int v) {
    color[v] = 1;

    for (int u: adj[v]) {
        if (color[u] == 0) {
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
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
    adj2.resize(n);
    color.assign(n, 0);

    int a, b;
    while (m--) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }

    cycle_start = -1;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && dfs(i))
            break;
    }

    if (cycle_start == -1) {
        vector<int> roots;
        color.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (adj[i].empty()) {
                roots.push_back(i);
            }
        }
        for (int v: roots) {
            dfs2(v);
        }
        //reverse(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i] + 1;
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
