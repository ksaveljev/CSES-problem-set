#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <list>
#include <cassert>
using namespace std;

#define ll long long
#define pb push_back
#define loop(a) for(int i = 0; i < a; i++)
#define loopv(i,a) for (int i = 0; i < a; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int maxN = 2e5+5;
int llog[maxN];
ll st[maxN][21];

int main(void) {
    int n, q;
    cin >> n >> q;

    llog[1] = 0;
    rep (i, 2, maxN) llog[i] = llog[i/2] + 1;

    loop(n) {
        cin >> st[i][0];
    }

    for (int j = 1; j < 21; j++) {
        for (int i = 0; i + (1<<j) <= n; i++) {
            st[i][j] = st[i][j-1] + st[i+(1<<(j-1))][j-1];
        }
    }

    int L, R;
    while (q--) {
        cin >> L >> R, --L, --R;

        ll sum = 0;
        for (int j = 20; j >= 0; j--) {
            if ((1<<j) <= R - L + 1) {
                sum += st[L][j];
                L += (1<<j);
            }
        }

        cout << sum << endl;
    }

    return 0;
}
