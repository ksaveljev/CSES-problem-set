#include <iostream>
#include <string>
#include <vector>
using namespace std;

using ll = long long;

const int nax = 1e6+5;
const int mod = 1e9+7;

int inv(int a) {
    return a <= 1 ? a : mod - (ll)(mod/a) * inv(mod % a) % mod;
}

int main(void) {
    string input;

    vector<ll> fact(nax);

    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < nax; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }

    cin >> input;

    vector<int> cnt(26, 0);
    for (int i = 0; i < input.size(); i++) {
        cnt[input[i]-'a']++;
    }

    ll result = fact[input.size()];
    for (int i = 0; i < 26; i++) {
        result = result * inv(fact[cnt[i]]) % mod;
    }

    cout << result << endl;

    return 0;
}
