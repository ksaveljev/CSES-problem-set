#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m, k, tmp;
    vector<int> desires;
    vector<int> actual;

    cin >> n >> m >> k;

    while (n--) {
        cin >> tmp;
        desires.push_back(tmp);
    }

    while (m--) {
        cin >> tmp;
        actual.push_back(tmp);
    }

    sort(desires.begin(), desires.end());
    sort(actual.begin(), actual.end());

    int result = 0;
    int didx = 0, aidx = 0;

    while (didx < desires.size() && aidx < actual.size()) {
        if (actual[aidx] < desires[didx] - k) {
            aidx++;
        } else if (actual[aidx] > desires[didx] + k) {
            didx++;
        } else {
            aidx++;
            didx++;
            result++;
        }
    }

    cout << result << endl;

    return 0;
}
