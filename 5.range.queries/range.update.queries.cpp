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

struct segtree {
    int size;
    vector<ll> tree;

    void build(vector<int> &a) {
        size = 1;
        while (size < a.size()) size *= 2;
        tree.assign(2*size, 0);
        build(a, 0, 0, size);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx == lx + 1) {
            if (lx < a.size()) {
                tree[x] = a[lx];
            }
        } else {
            int m = (lx + rx) / 2;
            build(a, 2*x+1, lx, m);
            build(a, 2*x+2, m, rx);
        }
    }

    void modify(int l, int r, int v) {
        modify(l, r, v, 0, 0, size);
    }

    void modify(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r) return;
        if (rx <= l) return;
        if (rx == lx + 1) {
            tree[x] += v;
            return;
        }
        if (lx >= l && rx <= r) {
            tree[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        modify(l, r, v, 2*x+1, lx, m);
        modify(l, r, v, 2*x+2, m, rx);
    }

    ll get(int idx) {
        return get(idx, 0, 0, size);
    }

    ll get(int idx, int x, int lx, int rx) {
        if (rx == lx + 1) {
            return tree[x];
        } else {
            int m = (lx + rx) / 2;
            if (idx < m)
                return get(idx, 2*x+1, lx, m) + tree[x];
            else
                return get(idx, 2*x+2, m, rx) + tree[x];
        }
    }
};

int main(void) {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    loop(n) cin >> a[i];

    segtree st;
    st.build(a);

    int cmd;
    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            --l;
            st.modify(l, r, v);
        } else {
            int i;
            cin >> i;
            --i;
            cout << st.get(i) << endl;
        }
    }

    return 0;
}
