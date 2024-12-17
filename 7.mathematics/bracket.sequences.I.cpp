#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

ll inv(ll v) {
    return v <= 1 ? v : mod - (mod/v) * inv(mod % v) % mod;
}

int main(void) {
    // DP recurrence: dp[i] = sum(dp[j] * dp[i - j - 1]) for j = 0 to i - 1
    // Unfortunatly, this is O(n^2) and will not pass the time limit
    // Therefore we need to use the formula for Catalan numbers

    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    n /= 2;

    vector<ll> fact(2*n+1);
    fact[0] = 1;
    for (int i = 1; i < 2*n+1; i++) {
        fact[i] = (i * fact[i-1]) % mod;
    }

    ll result = (fact[2*n] * inv(fact[n])) % mod;
    result *= (inv(n+1) * inv(fact[n])) % mod;
    result %= mod;

    cout << result << endl;

    return 0;
}
