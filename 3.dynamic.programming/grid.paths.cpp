#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

const int mod = 1e9+7;

int main(void) {
    int n;

    cin >> n;

    vector<vector<char>> field(n, vector<char>(n));
    vector<vector<ull>> dp(n, vector<ull>(n));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> field[i][j];
        }
    }

    if (field[0][0] == '.') {
        dp[0][0] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (field[i][j] == '*') continue;

            if (j + 1 < n && field[i][j+1] == '.') {
                dp[i][j+1] += dp[i][j];
                dp[i][j+1] = dp[i][j+1] % mod;
            }

            if (i + 1 < n && field[i+1][j] == '.') {
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] = dp[i+1][j] % mod;
            }
        }
    }

    cout << dp[n-1][n-1] << endl;

    return 0;
}
