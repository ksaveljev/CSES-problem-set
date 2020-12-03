#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9+7;

int main(void) {
    int n;

    cin >> n;

    vector<int> v(n);

    for (int& x: v) {
        cin >> x;
    }

    vector<int> dp(n+1, INF);
    dp[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        if (dp[j-1] < v[i] && v[i] < dp[j]) {
            dp[j] = v[i];
        }
    }

    int result = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[i] < INF) {
            result = i;
        }
    }

    cout << result << endl;

    return 0;
}
