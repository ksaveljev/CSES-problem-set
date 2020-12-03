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

    for (int i = 0; i < x + 1; i++) {
        for (int j = 0; j < n; j++) {
            if (i + coins[j] > x) continue;

            dp[i+coins[j]] += dp[i];
            dp[i+coins[j]] = dp[i+coins[j]] % mod;
        }
    }

    for (int j = 0; j < n; j++) {
        if (coins[j] <= x) dp[coins[j]]++;
        for (int i = 0; i < x + 1; i++) {
            if (dp[i] > 0 && i + coins[j] < x + 1) {
                dp[i+coins[j]] += dp[i];
                dp[i+coins[j]] = dp[i+coins[j]] % mod;
            }
        }

        /*
        for (int i = 0; i < x + 1; i++) {
            cout << dp[i] << " ";
        }
        cout << endl;
        */
    }

    cout << dp[x] << endl;
}
