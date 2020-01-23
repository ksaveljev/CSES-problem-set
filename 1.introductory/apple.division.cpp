#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
vector<ll> apples;
ll best = -1;
ll result = 0;

void find(ll target, int idx, ll sum) {
    if (sum >= target) {
        ll diff = sum - target;
        if (best == -1 || diff < best) {
            best = diff;
            result = sum;
        }
        return;
    }

    if (idx == n) {
        return;
    }

    find(target, idx + 1, sum + apples[idx]);
    find(target, idx + 1, sum);
}

int main(void) {
    ll sum = 0, tmp;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        sum += tmp;
        apples.push_back(tmp);
    }

    sort (apples.begin(), apples.end(), greater<ll>());

    find(sum/2, 0, 0);

    cout << abs((sum - result) - result) << endl;

    return 0;
}
