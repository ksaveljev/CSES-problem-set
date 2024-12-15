#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const int nax = 1e6 + 5;
const int mod = 1e9 + 7;

ll inv(ll v) {
    return v <= 1 ? v : mod - (ll)(mod/v) * inv(mod % v) % mod;
}

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<ll> fact(2*nax, 1);
    for (int i = 2; i < 2 * nax; i++) {
        fact[i] = (i * fact[i-1]) % mod;
    }

    cout << fact[m+n-1] * inv(fact[n-1] * fact[m] % mod) % mod << endl;

    return 0;
}
