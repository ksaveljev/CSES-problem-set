#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(void) {
    int n;
    cin >> n;

    vector<ll> sticks(n);
    ll sum = 0;

    for (ll& s: sticks) {
        cin >> s;
    }

    sort(sticks.begin(), sticks.end());

    int mid = n / 2;
    ll diff = 0;

    for (ll& s: sticks) {
        diff += abs(s - sticks[mid]);
    }

    cout << diff << endl;
}
