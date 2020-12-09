#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, k;
    cin >> n;

    vector<int> v;

    while (n--) {
        cin >> k;
        auto pos = upper_bound(v.begin(), v.end(), k) - v.begin();
        if (pos < v.size()) {
            v[pos] = k;
        } else {
            v.push_back(k);
        }
    }

    cout << v.size() << endl;

    return 0;
}
