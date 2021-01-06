#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int maxN = 20, mod = 1e9+7;
int n, m;
int adj[maxN][maxN];
ll dp[1<<maxN][maxN];

int main(void) {
    cin >> n >> m;

    int a, b;
    while (m--) {
        cin >> a >> b;
        --a, --b;
        adj[a][b]++;
    }

    dp[1][0] = 1;
    for (int i = 2; i < (1<<n); i++) {
        if (i & (1<<(n-1)) && i != (1<<n) - 1) continue;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                for (int k = 0; k < n; k++) {
                    if (i & (1 << k) && adj[k][j] && k != j && dp[i^(1<<j)][k]) {
                        dp[i][j] += adj[k][j] * dp[i^(1<<j)][k];
                        dp[i][j] %= mod;
                    }
                }
            }
        }
    }

    cout << dp[(1<<n)-1][n-1] << endl;

    return 0;
}
