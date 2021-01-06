#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> adj, adj2;
vector<int> st;
map<int,bool> visited;
vector<int> comp;

void dfs1(int v) {
    visited[v] = true;

    for (int u: adj[v]) {
        if (!visited[u]) {
            dfs1(u);
        }
    }

    st.push_back(v);
}

void dfs2(int v, int j) {
    visited[v] = true;
    comp[v] = j;

    for (int u : adj2[v]) {
        if (!visited[u]) {
            dfs2(u, j);
        }
    }
}

int main(void) {
    int n, m;

    cin >> n >> m;

    comp.resize(2 * m);
    adj.resize(2*m);
    adj2.resize(2*m);

    char c1, c2;
    int m1, m2;
    for (int i = 0; i < n; i++) {
        cin >> c1 >> m1 >> c2 >> m2;
        --m1, --m2;
        m1 *= 2;
        m2 *= 2;

        if (c1 == '-') m1 ^= 1;
        if (c2 == '-') m2 ^= 1;

        adj[m1^1].push_back(m2);
        adj[m2^1].push_back(m1);
    }

    for (int i = 0; i < 2 * m; i++) {
        for (int j: adj[i]) {
            adj2[j].push_back(i);
        }
    }

    for (int i = 0; i < 2 * m; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    reverse(st.begin(), st.end());
    visited.clear();

    for (int i = 0, j = 0; i < 2 * m; i++) {
        if (!visited[st[i]]) {
            dfs2(st[i], j++);
        }
    }

    for (int i = 0; i < 2 * m; i++) {
        if (comp[i] == comp[i^1]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for (int i = 0; i < m; i++) {
        char ans = comp[2*i] > comp[2*i+1] ? '+' : '-';
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
