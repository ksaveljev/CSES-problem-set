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
#include <sstream>
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

int main(void) {
    int q;
    cin >> q;

    ll idx;
    while (q--) {
        cin >> idx;
        ll len = 1;
        ll limit = 9;
        while (idx > limit * len) {
            idx -= limit * len;
            limit *= 10;
            len++;
        }
        ll start = 1;
        for (int i = 2; i <= len; i++) {
            start *= 10;
        }
        start--;
        start += idx / len;
        ll r = idx % len;
        if (r == 0) {
            cout << start % 10 << endl;
        } else {
            stringstream ss;
            ss << start + 1;
            string tmp;
            ss >> tmp;

            cout << tmp[r-1] << endl;
        }
    }

    return 0;
}
