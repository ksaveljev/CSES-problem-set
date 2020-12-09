#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

int main(void) {
    int n, x;

    cin >> n >> x;

    vector<int> nums(n);
    map<int,vector<pair<int,int>>> m;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i-1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ll s = nums[i-1] + nums[j-1];
            m[s].push_back({i, j});
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int s = nums[i-1] + nums[j-1];
            int diff = x - s;
            if (m.find(diff) == m.end()) continue;
            for (auto [a, b]: m[diff]) {
                if (a != i && a !=j && b != i && b != j) {
                    cout << i << " " << j << " " << a << " " << b << endl;
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
