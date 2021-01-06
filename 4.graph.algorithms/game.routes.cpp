#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll mod = 1e9+7;

vector<vector<int>> adj;
vector<ll> dp;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;

    for (int u: adj[v]) {
        if (!visited[u])
            dfs(u);

        dp[v] = (dp[u] + dp[v]) % mod;
    }
}

int main(void) {
    int n, m;

    cin >> n >> m;

    adj.resize(n);
    dp.assign(n, 0);
    visited.assign(n, false);

    int a, b;
    while (m--) {
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
    }

    dp[n-1] = 1;
    dfs(0);

    cout << dp[0] << endl;

    return 0;
}
