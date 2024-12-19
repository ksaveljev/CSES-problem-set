#include <iostream>
#include <cstring>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

int main(void) {
    ll n;
    cin >> n;

    ll product[6][6] = {0};
    for (int i = 0; i < 6; i++) {
        product[i][i] = 1;
    }

    ll tm[6][6] = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
    };

    ll tmp[6][6];
    while (n > 0) {
        if (n & 1) {
            memset(tmp, 0, sizeof(tmp));
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    for (int k = 0; k < 6; k++) {
                        tmp[i][k] = (tmp[i][k] + product[i][j] * tm[j][k]) % mod;
                    }
                }
            }

            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    product[i][j] = tmp[i][j];
                }
            }
        }

        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 6; k++) {
                    tmp[i][k] = (tmp[i][k] + tm[i][j] * tm[j][k]) % mod;
                }
            }
        }

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                tm[i][j] = tmp[i][j];
            }
        }

        n /= 2;
    }

    cout << product[0][0] << endl;

    return 0;
}
