#include <iostream>
using namespace std;

#define MOD 1000000007
typedef long long ll;

int main(void) {
    int n;
    ll result = 2;

    cin >> n;

    for (int i = 2; i <= n; i++) {
        result = (result * 2) % MOD;
    }

    cout << result << endl;

    return 0;
}
