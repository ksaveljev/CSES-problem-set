#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

int main(void) {
    int n, x;

    cin >> n >> x;

    vector<pair<ll, int>> nums(n);
    map<int,vector<pair<int,int>>> m;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i-1].first;
        nums[i-1].second = i;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            ll sum = nums[i].first + nums[j].first + nums[k].first;
            if (sum == x) {
                cout << nums[i].second << " " << nums[j].second << " " << nums[k].second << endl;
                return 0;
            } else if (sum < x) {
                j++;
            } else {
                k--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
