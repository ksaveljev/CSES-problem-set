#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;
const int nax = 1e6 + 5;

int main(void) {
    int n;
    cin >> n;

    vector<int> d(nax);
    d[1] = 0;
    d[2] = 1;
    for (int i = 3; i < nax; i++) {
        d[i] = ((ll)(i - 1) * (d[i - 1] + d[i - 2])) % mod;
    }

    cout << d[n] << endl;

    return 0;
}
