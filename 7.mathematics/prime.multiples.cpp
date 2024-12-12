#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main(void) {
    ll n;
    int k;

    cin >> n >> k;
    vector<ll> primes(k);
    for (auto &p : primes) {
        cin >> p;
    }

    ll result = 0;

    for (int i = 1; i < (1 << k); i++) {
        vector<ll> taken;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                taken.push_back(primes[j]);
            }
        }

        ll product = 1;
        for (auto p : taken) {
            if (product > n / p) {
                product = n + 1;
                break;
            }
            product *= p;
        }

        if (taken.size() % 2 == 1) {
            result += n / product;
        } else {
            result -= n / product;
        }
    }

    cout << result << endl;

    return 0;
}
