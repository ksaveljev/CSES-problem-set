#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, m;
vector<int> k;
vector<vector<int>> adj, adj2, adj3;
vector<long long> dp, kk;
map<int,bool> visited;
vector<int> st;
map<int,int> comp;

void dfs1(int v) {
    visited[v] = true;

    for (auto u: adj[v]) {
        if (!visited[u]) {
            dfs1(u);
        }
    }

    st.push_back(v);
}

void dfs2(int v, int j) {
    visited[v] = true;
    comp[v] = j;

    for (auto u: adj2[v]) {
        if (!visited[u]) {
            dfs2(u, j);
        }
    }

    kk[comp[v]] += k[v];
}

void dfs3(int v) {
    visited[v] = true;
    for (auto u: adj3[v]) {
        if (!visited[u]) {
            dfs3(u);
        }
        dp[v] = max(dp[v], dp[u]);
    }
    dp[v] += kk[v];
}

int main(void) {
    cin >> n >> m;

    k.resize(n);
    adj.resize(n);
    adj2.resize(n);
    adj3.resize(n);
    kk.resize(n);
    dp.resize(n);

    for (int i = 0; i < n; i++)
        cin >> k[i];

    int a, b;
    while (m--) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    reverse(st.begin(), st.end());
    visited.clear();

    for (int i = 0; i < n; i++) {
        if (!visited[st[i]]) {
            dfs2(st[i], st[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j: adj[i]) {
            if (comp[i] != comp[j]) {
                adj3[comp[i]].push_back(comp[j]);
            }
        }
    }

    long long result = 0;
    visited.clear();

    for (int i = 0; i < n; i++) {
        if (i == comp[i] && !visited[i]) {
            dfs3(i);
            result = max(dp[i], result);
        }
    }

    cout << result << endl;

    return 0;
}
