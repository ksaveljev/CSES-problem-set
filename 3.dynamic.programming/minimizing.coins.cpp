#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9+7;

int main(void) {
    int n, x;

    cin >> n >> x;

    vector<int> coins(n);

    for (int& x: coins) {
        cin >> x;
    }

    sort(coins.begin(), coins.end());

    vector<vector<int>> dp(n+1, vector<int>(x + 1, INF));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j < coins[i-1]) {
                dp[i][j] = dp[i-1][j];
                continue;
            }

            dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
        }
    }

    if (dp[n][x] == INF) {
        cout << -1 << endl;
    } else {
        cout << dp[n][x] << endl;
    }

    return 0;
}
