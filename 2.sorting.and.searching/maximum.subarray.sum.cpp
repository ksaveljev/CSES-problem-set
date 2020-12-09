#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main(void) {
    int n;

    cin >> n;

    vector<ll> v(n);

    for (ll& x: v) {
        cin >> x;
    }

    ll sum = 0, best = v[0];
    for (int i = 0; i < n; i++) {
        sum = max(v[i], sum + v[i]);
        best = max(best, sum);
    }

    cout << best << endl;

    return 0;
}
