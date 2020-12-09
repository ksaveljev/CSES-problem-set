#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int main(void) {
    int n, t;

    cin >> n >> t;

    vector<int> k(n);

    for (int& x: k) {
        cin >> x;
    }

    ull start = 1;
    ull end = 1e18;

    while (start < end) {
        ull sum = 0;
        ull mid = (start + end) / 2;
        for (int& x: k) {
            sum += mid / x;
        }
        if (sum >= t) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }

    cout << start << endl;

    return 0;
}
