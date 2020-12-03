#include <iostream>
#include <vector>
using namespace std;

const int nax = 1e6+1;
const int mod = 1e9+7;

typedef unsigned long long ull;

int main(void) {
    vector<ull> dp(nax);

    dp[0] = 1;

    for (int i = 0; i < nax; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i + j < nax) {
                dp[i+j] += dp[i];
                dp[i+j] = dp[i+j] % mod;
            }
        }
    }

    int n;

    cin >> n;

    cout << dp[n] << endl;

    return 0;
}
