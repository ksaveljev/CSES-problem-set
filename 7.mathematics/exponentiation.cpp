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

const int MOD = 1e9+7;

ll pM(ll a, ll b, ll m) {
    ll r = 1;
    while (b) {
        if (b & 1) {
            r = (r * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }

    return r;
}

int main(void) {
    int n;
    cin >> n;

    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << pM(a, b, MOD) << "\n";
    }

    return 0;
}
