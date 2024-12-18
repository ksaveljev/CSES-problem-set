#include <iostream>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7;

typedef struct _matrix {
    long long m[2][2];
    _matrix() {
        memset(m, 0, sizeof(m));
    }
} matrix;

matrix mul(const matrix &one, const matrix &two) {
    matrix result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result.m[i][k] = (result.m[i][k] + one.m[i][j] * two.m[j][k]) % mod;
            }
        }
    }
    return result;
}

int main(void) {
    long long n;
    cin >> n;

    if (n < 2) {
        cout << n << endl;
        return 0;
    }

    matrix product;
    product.m[0][0] = 1;
    product.m[1][1] = 1;

    matrix fib;
    fib.m[0][0] = 0;
    fib.m[0][1] = 1;
    fib.m[1][0] = 1;
    fib.m[1][1] = 1;

    while (n > 0) {
        if (n & 1) {
            product = mul(product, fib);
        }
        fib = mul(fib, fib);
        n /= 2;
    }

    cout << product.m[0][1] << endl;

    return 0;
}
