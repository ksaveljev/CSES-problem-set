#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main(void) {
    int n;

    cin >> n;

    vector<int> x(n);

    int sum = 0;

    for (int& c: x) {
        cin >> c;
        sum += c;
    }

    unordered_set<int> sums;

    sums.insert(x[0]);

    for (int i = 1; i < n; i++) {
        unordered_set<int> tmp(sums.begin(), sums.end());
        tmp.insert(x[i]);
        for (int c: sums) {
            tmp.insert(c+x[i]);
        }

        sums = tmp;
    }

    cout << sums.size() << endl;
    vector<int> result(sums.begin(), sums.end());
    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}
