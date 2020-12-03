#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main(void) {
    int n;

    cin >> n;

    vector<int> x(n);

    for (int& c: x) {
        cin >> c;
    }

    vector<vector<pair<ll,ll>>> dp(n, vector<pair<ll,ll>>(n));

    for (int i = 0; i < n; i++) {
        dp[i][i] = make_pair(x[i], 0);
    }

    for (int len = 2; len <= n; len++) {
        for (int L = 0; L < n; L++) {
            int R = L + len - 1;
            if (R >= n) break;

            if (x[L] + dp[L+1][R].second > dp[L][R-1].second + x[R]) {
                dp[L][R].first = x[L] + dp[L+1][R].second;
                dp[L][R].second = dp[L+1][R].first;
            } else {
                dp[L][R].first = dp[L][R-1].second + x[R];
                dp[L][R].second = dp[L][R-1].first;
            }
        }
    }

    cout << dp[0][n-1].first << endl;

    return 0;
}
