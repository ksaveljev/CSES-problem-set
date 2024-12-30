#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

using ll = long long;

double dp[103][603];

int main(void) {
    int n, a, b;
    cin >> n >> a >> b;

    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 * i; j++) {
            for (int k = 1; k <= 6; k++) {
                dp[i][j] += (j - k >= 0 ? dp[i - 1][j - k] : 0);
            }
            dp[i][j] /= 6.0;
        }
    }

    double result = 0;
    for (int i = a; i <= b; i++) {
        result += dp[n][i];
    }

    result *= 1e6;
    result = llround(result);
    result /= 1e6;

    cout << fixed << setprecision(6) << result << endl;

    return 0;
}
