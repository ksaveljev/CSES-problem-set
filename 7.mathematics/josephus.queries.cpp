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

ll josephus(ll n, ll k) {
    if (n == 1) {
        return 1;
    }

    if (k <= (n + 1) / 2) {
        if (2 * k > n) {
            return (2 * k) % n;
        } else {
            return 2 * k;
        }
    }

    ll x = josephus(n / 2, k - (n + 1) / 2);
    if (n & 1) {
        return 2 * x + 1;
    } else {
        return 2 * x - 1;
    }
}

int main(void) {
    int q;
    cin >> q;

    while (q--) {
        int n, k;
        cin >> n >> k;
        cout << josephus(n, k) << "\n";
    }

    return 0;
}
