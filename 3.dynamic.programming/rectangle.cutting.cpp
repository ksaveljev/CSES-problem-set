#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9+7;

int main(void) {
    int a, b;

    cin >> a >> b;

    vector<vector<int>> dp(a+1, vector<int>(b+1, INF));

    for (int i = 1; i <= a; i++) {
        dp[i][1] = i - 1;
    }
    for (int i = 1; i <= b; i++) {
        dp[1][i] = i - 1;
    }

    for (int i = 2; i <= a; i++) {
        for (int j = 2; j <= b; j++) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
                }
                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
                }
            }
        }
    }

    cout << dp[a][b] << endl;

    return 0;
}
