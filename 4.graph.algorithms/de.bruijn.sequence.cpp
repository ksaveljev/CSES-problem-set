#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 1 << 15;
int n;
vector<pair<int,int>> adj[maxN];
vector<int> result;
bool visited[maxN];

void dfs(int v) {
    for (auto [u, e]: adj[v]) {
        if (!visited[e]) {
            visited[e] = true;
            dfs(u);
            result.push_back(e % 2);
        }
    }
}

int main(void) {
    cin >> n;

    for (int i = 0; i < (1 << n); i++) {
        int v = i >> 1;
        int u = i & ((1<<(n-1))-1);
        adj[v].push_back({u, i});
    }

    dfs(0);
    reverse(result.begin(), result.end());
    for (int i = 0; i < n - 1; i++) cout << 0;
    for (auto x: result) cout << x;
    cout << endl;

    return 0;
}
