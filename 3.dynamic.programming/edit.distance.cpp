#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    string a, b;

    cin >> a >> b;

    int an = a.size();
    int bn = b.size();

    vector<vector<int>> dp(an + 1, vector<int>(bn + 1));

    for (int i = 0; i < bn + 1; i++) {
        dp[0][i] = i;
    }

    for (int i = 0; i < an + 1; i++) {
        dp[i][0] = i;
    }

    for (int i = 1; i <= an; i++) {
        for (int j = 1; j <= bn; j++) {
            dp[i][j] = min(
                min(
                    dp[i-1][j] + 1,
                    dp[i][j-1] + 1
                ),
                dp[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 1)
            );
        }
    }

    cout << dp[an][bn] << endl;

    return 0;
}
