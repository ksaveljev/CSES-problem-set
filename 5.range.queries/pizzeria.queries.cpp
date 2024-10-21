#include <iostream>
#include <vector>
#include <climits>
using namespace std;

using ll = long long;

struct segtree {
    struct node {
        ll minL, minR;
    };
    int size;
    vector<node> tree;

    node combine(const node &a, const node &b) {
        return {
            min(a.minL, b.minL),
            min(a.minR, b.minR)
        };
    }

    void build(const vector<int> &v) {
        size = 1;
        while (size < v.size()) size *= 2;
        tree.assign(2*size, {INT_MAX, INT_MAX});
        build(v, 0, 0, size);
    }

    void build(const vector<int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < v.size()) {
                tree[x] = {v[lx] + lx, v[lx] - lx};
            }
        } else {
            int m = (lx + rx) / 2;
            build(v, 2 * x + 1, lx, m);
            build(v, 2 * x + 2, m, rx);
            tree[x] = combine(tree[2*x+1], tree[2*x+2]);
        }
    }

    void update(int i, ll v) {
        update(i, v, 0, 0, size);
    }

    void update(int i, ll v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = {v + lx, v - lx};
        } else {
            int m = (lx + rx) / 2;
            if (i < m) {
                update(i, v, 2 * x + 1, lx, m);
            } else {
                update(i, v, 2 * x + 2, m, rx);
            }
            tree[x] = combine(tree[2*x+1], tree[2*x+2]);
        }
    }

    ll query(int k) {
        return query(k, 0, 0, size);
    }

    ll query(int k, int x, int lx, int rx) {
        if (k >= rx) {
            return tree[x].minR + k;
        } else if (k < lx) {
            return tree[x].minL - k;
        } else if (rx - lx == 1) {
            return (tree[x].minL + tree[x].minR) / 2;
        } else {
            int m = (lx + rx) / 2;
            int left = query(k, 2 * x + 1, lx, m);
            int right = query(k, 2 * x + 2, m, rx);
            return min(left, right);
        }
    }
};

int main(void) {
    int n, q;
    cin >> n >> q;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    segtree st;
    st.build(p);

    int t, k, x;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> k >> x;
            st.update(k-1, x);
        } else {
            cin >> k;
            cout << st.query(k-1) << '\n';
        }
    }

    return 0;
}
