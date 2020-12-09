#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int main(void) {
    ull n, k;
    cin >> n >> k;

    vector<ull> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    ull left = *max_element(x.begin(), x.end());
    ull right = 1e18;

    while (left < right) {
        ull m = (left + right) / 2;
        int count = 0;
        ull sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + x[i] > m) {
                count++;
                sum = x[i];
            } else {
                sum += x[i];
            }
        }
        count++;

        if (count > k) {
            left = m + 1;
        } else {
            right = m;
        }
    }

    cout << left << endl;

    return 0;
}
