#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int maxN = 2e5+1;
int t[maxN][30];

int main(void) {
    int n, q;

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> t[i][0];
        t[i][0]--;
    }

    for (int j = 1; j < 30; j++) {
        for (int i = 0; i < n; i++) {
            t[i][j] = t[t[i][j-1]][j-1];
        }
    }

    int x, k;
    while (q--) {
        cin >> x >> k;
        x--;

        for (int i = 0; i < 30; i++) {
            if ((k >> i) & 1) {
                x = t[x][i];
            }
        }

        cout << x + 1 << endl;
    }
    return 0;
}
