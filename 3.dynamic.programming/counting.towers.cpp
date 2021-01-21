#include <iostream>
using namespace std;

#define ll long long

const int mod = 1e9+7;
const int maxN = 1e6;

ll dp[maxN+1][2];

int main(void) {
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= maxN; i++) {
        ll a = (dp[i-1][0] + dp[i-1][1]) % mod;
        ll b = dp[i-1][0];
        ll c = (2 * dp[i-1][0]) % mod;
        ll d = dp[i-1][1];

        dp[i][0] = (a + b + c) % mod;
        dp[i][1] = (a + d) % mod;
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << endl;
    }
}
