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

struct segree {
    int size;
    vector<ll> s;

    void build(vector<int> &v) {
        size = 1;
        while (size < v.size()) size *= 2;
        s.assign(2*size, 0);
        build(v, 0, 0, size);
    }

    void build(vector<int> &v, int x, int lx, int rx) {
        if (rx == lx + 1) {
            if (lx < v.size()) {
                s[x] = v[lx];
            }
        } else {
            int m = (lx + rx) / 2;
            build(v, 2*x+1, lx, m);
            build(v, 2*x+2, m, rx);
            s[x] = s[2*x+1] + s[2*x+2];
        }
    }

    void set(int idx, int v) {
        set(idx, v, 0, 0, size);
    }

    void set(int idx, int v, int x, int lx, int rx) {
        if (rx == lx + 1) {
            s[x] = v;
        } else {
            int m = (lx + rx) / 2;
            if (idx < m)
                set(idx, v, 2*x+1, lx, m);
            else
                set(idx, v, 2*x+2, m, rx);
            s[x] = s[2*x+1] + s[2*x+2];
        }
    }

    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

    ll sum(int l, int r, int x, int lx, int rx) {
        if (rx <= l) return 0;
        if (lx >= r) return 0;
        if (lx >= l && rx <= r) return s[x];
        int m = (lx + rx) / 2;
        return sum(l, r, 2*x+1, lx, m) + sum(l, r, 2*x+2, m, rx);
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
            cout << st.sum(a,b) << endl;
        }
    }
    return 0;
}
