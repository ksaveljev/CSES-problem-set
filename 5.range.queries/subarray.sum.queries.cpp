#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

struct segtree {
    struct node {
        ll seg;
        ll pref;
        ll suf;
        ll sum;
    };
    int size;
    vector<node> tree;

    node combine(const node& a, const node& b) {
        return {
            max(max(a.seg, b.seg), a.suf + b.pref),
            max(a.pref, a.sum + b.pref),
            max(b.suf, b.sum + a.suf),
            a.sum + b.sum
        };
    }

    void build(const vector<int> &v) {
        size = 1;
        while (size < v.size()) size *= 2;
        tree.assign(2 * size, {0, 0, 0});
        build(v, 0, 0, size);
    }

    void build(const vector<int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < v.size()) {
                if (v[lx] < 0) {
                    tree[x] = {0, 0, 0, v[lx]};
                } else {
                    tree[x] = {v[lx], v[lx], v[lx], v[lx]};
                }
            }
        } else {
            int m = (lx + rx) / 2;
            build(v, 2 * x + 1, lx, m);
            build(v, 2 * x + 2, m, rx);
            tree[x] = combine(tree[2*x+1], tree[2*x+2]);
        }
    }

    void update(int idx, int v) {
        update(idx, v, 0, 0, size);
    }

    void update(int idx, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (v < 0) {
                tree[x] = {0, 0, 0, v};
            } else {
                tree[x] = {v, v, v, v};
            }
        } else {
            int m = (lx + rx) / 2;
            if (idx < m) {
                update(idx, v, 2 * x + 1, lx, m);
            } else {
                update(idx, v, 2 * x + 2, m, rx);
            }
            tree[x] = combine(tree[2*x+1], tree[2*x+2]);
        }
    }

    ll query() {
        return tree[0].seg;
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    segtree st;
    st.build(x);

    int idx, v;
    while (m--) {
        cin >> idx >> v;
        st.update(idx - 1, v);
        cout << st.query() << '\n';
    }

    return 0;
}
