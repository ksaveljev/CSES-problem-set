#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> adj2;
vector<int> st;
map<int,bool> visited;
vector<vector<int>> components;

void dfs1(int v) {
    visited[v] = true;
    for (int u: adj[v]) {
        if (!visited[u]) {
            dfs1(u);
        }
    }
    st.push_back(v);
}

void dfs2(int v) {
    visited[v] = true;
    components[components.size()-1].push_back(v);
    for (int u : adj2[v]) {
        if (!visited[u]) {
            dfs2(u);
        }
    }
}

int main(void) {
    int n, m;

    cin >> n >> m;
    adj.resize(n);
    adj2.resize(n);

    int a, b;
    while (m--) {
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    visited.clear();

    reverse(st.begin(), st.end());

    for (int i = 0; i < n; i++) {
        if (!visited[st[i]]) {
            components.push_back({});
            dfs2(st[i]);
        }
    }

    if (components.size() == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        cout << components[1][0] + 1 << " " << components[0][0] + 1 << endl;
    }

    return 0;
}
