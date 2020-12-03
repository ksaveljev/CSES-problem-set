#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, s, tmp;
    vector< pair<int,int> > nums;
    pair<int, int> result = make_pair(-1, -1);

    cin >> n >> s;

    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        nums.push_back(make_pair(tmp, i));
    }

    sort(nums.begin(), nums.end());

    bool found = false;
    for (int i = 0; !found && i < n - 1; i++) {
        if (nums[i].first >= s) {
            break;
        }

        int a = i + 1;
        int b = n - 1;
        int target = s - nums[i].first;
        while (!found && a <= b) {
            int k = (a + b) / 2;
            if (nums[k].first == target) {
                found = true;
                result = make_pair(nums[i].second, nums[k].second);
            } else if (nums[k].first < target) {
                a = k + 1;
            } else {
                b = k - 1;
            }
        }
    }

    if (found) {
        cout << result.first << " " << result.second << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
