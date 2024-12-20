#include <iostream>
#include <cstring>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;
const int nax = 101;

ll adj[nax][nax];
ll product[nax][nax];
ll tmp[nax][nax];

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;

    memset(adj, 0, sizeof(adj));
    memset(product, 0, sizeof(product));

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a-1][b-1]++;
    }
    
    for (int i = 0; i < n; i++) {
        product[i][i] = 1;
    }

    while (k > 0) {
        if (k & 1) {
            memset(tmp, 0, sizeof(tmp));
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    for (int k = 0; k < n; k++)
                        tmp[i][k] = (tmp[i][k] + product[i][j] * adj[j][k]) % mod;

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    product[i][j] = tmp[i][j];
        }

        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    tmp[i][k] = (tmp[i][k] + adj[i][j] * adj[j][k]) % mod;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = tmp[i][j];

        k /= 2;
    }

    cout << product[0][n-1] << endl;

    return 0;
}
