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
#include <climits>
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

void calc(int c, int n, vector<string>& v) {
    if (c == n) {
        for (auto& x : v) {
            cout << x << endl;
        }
        return;
    }

    vector<string> vv;
    for (int i = 0; i < v.size(); i++) {
        vv.push_back("0" + v[i]);
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        vv.push_back("1" + v[i]);
    }

    calc(c + 1, n, vv);
}

int main(void) {
    int n;
    cin >> n;

    vector<string> v = {"0", "1"};
    calc(1, n, v);

    return 0;
}
