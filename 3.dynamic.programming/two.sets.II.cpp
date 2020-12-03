#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9+7;

typedef unsigned long long ull;

int main(void) {
    int n;

    cin >> n;

    int maxN = n * (n + 1) / 2;

    if (maxN % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    maxN /= 2;

    vector<vector<ull>> dp(n+1, vector<ull>(maxN+1));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= maxN; j++) {
            dp[i][j] = (dp[i-1][j] + (j>=i?dp[i-1][j-i]:0)) % mod;
        }
    }

    cout << dp[n][maxN] << endl;

    return 0;
}
