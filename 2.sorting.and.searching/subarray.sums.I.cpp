#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main(void) {
    ll n, x;

    cin >> n >> x;

    vector<ll> nums(n);

    for (ll& num: nums) {
        cin >> num;
    }

    int result = 0;

    int start = 0;
    int end = 0;
    ll sum = 0;

    while (end < n) {
        sum += nums[end];
        end++;

        while (sum > x) {
            sum -= nums[start];
            start++;
        }

        if (sum == x) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}
