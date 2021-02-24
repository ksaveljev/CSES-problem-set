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

struct segree {
    int size;
    vector<int> mmin;

    void build(vector<int> &v) {
        size = 1;
        while (size < v.size()) size *= 2;
        mmin.assign(2*size, INT_MAX);
        build(v, 0, 0, size);
    }

    void build(vector<int> &v, int x, int lx, int rx) {
        if (rx == lx + 1) {
            if (lx < v.size()) {
                mmin[x] = v[lx];
            }
        } else {
            int m = (lx + rx) / 2;
            build(v, 2*x+1, lx, m);
            build(v, 2*x+2, m, rx);
            mmin[x] = ::min(mmin[2*x+1], mmin[2*x+2]);
        }
    }

    void set(int idx, int v) {
        set(idx, v, 0, 0, size);
    }

    void set(int idx, int v, int x, int lx, int rx) {
        if (rx == lx + 1) {
            mmin[x] = v;
        } else {
            int m = (lx + rx) / 2;
            if (idx < m)
                set(idx, v, 2*x+1, lx, m);
            else
                set(idx, v, 2*x+2, m, rx);
            mmin[x] = ::min(mmin[2*x+1], mmin[2*x+2]);
        }
    }

    int min(int l, int r) {
        return min(l, r, 0, 0, size);
    }

    int min(int l, int r, int x, int lx, int rx) {
        if (lx >= r) return INT_MAX;
        if (rx <= l) return INT_MAX;
        if (lx >= l && rx <= r) return mmin[x];
        int m = (lx + rx) / 2;
        return ::min(min(l, r, 2*x+1, lx, m), min(l, r, 2*x+2, m, rx));
    }
};

int main(void) {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    loop(n) cin >> v[i];

    segree st;
    st.build(v);

    int cmd;
    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            int k, u;
            cin >> k >> u;
            --k;
            st.set(k, u);
        } else {
            int a, b;
            cin >> a >> b;
            --a;
            cout << st.min(a,b) << endl;
        }
    }
    return 0;
}
