#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

struct segtree {
    struct node {
        long long pref;
        long long sum;
    };

    int size;
    vector<node> tree;

    node combine(node &a, node &b) {
        return {
            max(a.pref, a.sum + b.pref),
            a.sum + b.sum,
        };
    }

    void build(vector<int> &v) {
        size = 1;
        while (size < v.size()) size *= 2;
        tree.assign(2 * size, {0, 0});
        build(v, 0, 0, size);
    }

    void build(vector<int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < v.size()) {
                if (v[lx] < 0) {
                    tree[x] = {0, v[lx]};
                } else {
                    tree[x] = {v[lx], v[lx]};
                }
            }
        } else {
            int m = (lx + rx) / 2;
            build(v, 2 * x + 1, lx, m);
            build(v, 2 * x + 2, m, rx);
            tree[x] = combine(tree[2*x+1], tree[2*x+2]);
        }
    }

    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }

    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (v < 0) {
                tree[x] = {0, v};
            } else {
                tree[x] = {v, v};
            }
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

    ll query(int l, int r) {
        return query(l, r, 0, 0, size).pref;
    }

    node query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return {0, 0};
        if (lx >= l && rx <= r) return tree[x];
        int m = (lx + rx) / 2;
        node r1 = query(l, r, 2 * x + 1, lx, m);
        node r2 = query(l, r, 2 * x + 2, m, rx);
        return combine(r1, r2);
    }
};

int main(void) {
    int n, q;
    cin >> n >> q;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    segtree st;
    st.build(x);

    int t, a, b;
    while (q--) {
        cin >> t >> a >> b;
        a--;
        if (t == 1) {
            st.update(a, b);
        } else { // t == 2
            cout << st.query(a, b) << endl;
        }
    }

    return 0;
}
