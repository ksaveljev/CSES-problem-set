#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

int main(void) {
    ll n, x;

    cin >> n;

    vector<ll> nums(n);
    map<ll, int> m;
    m[0]++;
    ll sum = 0;
    ll result = 0;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum = (sum + nums[i] % n + n) % n;
        result += m[sum];
        m[sum]++;
    }

    cout << result << endl;

    return 0;
}
