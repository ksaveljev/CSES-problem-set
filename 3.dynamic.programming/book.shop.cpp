#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, x;

    cin >> n >> x;

    vector<int> price(n);
    vector<int> pages(n);

    for (int& p: price) {
        cin >> p;
    }

    for (int& p: pages) {
        cin >> p;
    }

    vector<vector<int>> dp(n+1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (price[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-price[i-1]] + pages[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}
