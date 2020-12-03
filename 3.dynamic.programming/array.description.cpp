#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9+7;

typedef unsigned long long ull;

int main(void) {
    int n, m;

    cin >> n >> m;

    vector<int> v(n);

    for (int& x : v) {
        cin >> x;
    }

    for (int i = 1; i < n; i++) {
        if (v[i] != 0 && v[i-1] != 0) {
            if (abs(v[i] - v[i-1]) > 1) {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    vector<vector<ull>> dp(n+1, vector<ull>(m+1));

    for (int i = 1; i <= m; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (i == 1) {
                if (v[i-1] == 0 || j == v[i-1]) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            } else {
                if (v[i-1] == 0) {
                    dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j]) % mod + (j+1>m?0:dp[i-1][j+1])) % mod;
                } else {
                    if (v[i-2] == 0) {
                        if (j == v[i-1]) {
                            dp[i][j] = ((dp[i-1][v[i-1]-1] + dp[i-1][v[i-1]]) % mod + (v[i-1]+1>m?0:dp[i-1][v[i-1]+1])) % mod;
                        } else {
                            dp[i][j] = 0;
                        }
                    } else {
                        if (j == v[i-1]) {
                            dp[i][j] = dp[i-1][v[i-2]];
                        } else {
                            dp[i][j] = 0;
                        }
                    }
                }
            }

        }
    }

    ull result = 0;

    for (int i = 1; i <= m; i++) {
        result = (result + dp[n][i]) % mod;
    }

    cout << result << endl;

    return 0;
}
