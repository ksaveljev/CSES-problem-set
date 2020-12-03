#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9+7;

int main(void) {
    int n;

    cin >> n;

    vector dp(n+1, INF);

    dp[n] = 0;

    for (int i = n; i > 0; i--) {
        int tmp = i;

        while (tmp > 0) {
            int x = tmp % 10;
            tmp /= 10;

            dp[i - x] = min(dp[i-x], dp[i] + 1);
        }
    }


    cout << dp[0] << endl;
}
