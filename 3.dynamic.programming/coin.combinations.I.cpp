#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1e9+7;

typedef unsigned long long ull;

int main(void) {
    int n, x;

    cin >> n >> x;

    vector<int> coins(n);

    for (int& c: coins) {
        cin >> c;
    }

    sort(coins.begin(), coins.end());

    vector<ull> dp(x+1);
    dp[0] = 1;

    for (int i = 0; i < x + 1; i++) {
        for (int j = 0; j < n; j++) {
            if (i + coins[j] > x) continue;

            dp[i+coins[j]] += dp[i];
            dp[i+coins[j]] = dp[i+coins[j]] % mod;
        }
    }

    cout << dp[x] << endl;
}
