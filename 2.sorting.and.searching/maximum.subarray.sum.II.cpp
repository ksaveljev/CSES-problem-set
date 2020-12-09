#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;

int main(void) {
    int n, a, b;

    cin >> n >> a >> b;
    vector<ll> sum(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }

    ll result = -1e18-5;

    set<pair<ll,ll>> s;

    for (int i = 0; i <= n; i++) {
        if (i >= a) {
            s.insert({sum[i - a], i - a});
        }

        if (!s.empty()) {
            result = max(result, sum[i] - s.begin()->first);
        }

        if (i >= b) {
            s.erase({sum[i - b], i - b});
        }
    }

    cout << result << endl;
}
