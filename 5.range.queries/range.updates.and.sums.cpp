#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

struct segtree {
    struct node {
        ll assign;
        ll add;
        ll value;
    };

    int size;
    vector<node> tree;

    void build(vector<int> &v) {
        size = 1;
        while (size < v.size()) size *= 2;
        tree.assign(2 * size, {0, 0, 0});
        build(v, 0, 0, size);
    }

    void build(vector<int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < v.size()) {
                tree[x].value = v[lx];
            }
        } else {
            int m = (lx + rx) / 2;
            build(v, 2 * x + 1, lx, m);
            build(v, 2 * x + 2, m, rx);
            tree[x].value = tree[2*x+1].value + tree[2*x+2].value;
        }
    }

    void propagate(int x, int lx, int rx) {
        if (tree[x].add == 0 && tree[x].assign == 0) return;
        if (rx - lx == 1) return;

        int m = (lx + rx) / 2;

        if (tree[x].assign != 0) {
            tree[2*x+1].assign = tree[x].assign;
            tree[2*x+1].add = 0;
            tree[2*x+1].value = tree[x].assign * (m - lx);

            tree[2*x+2].assign = tree[x].assign;
            tree[2*x+2].add = 0;
            tree[2*x+2].value = tree[x].assign * (rx - m);
        }
        
        if (tree[x].add != 0) {
            tree[2*x+1].add += tree[x].add;
            tree[2*x+1].value += tree[x].add * (m - lx);

            tree[2*x+2].add += tree[x].add;
            tree[2*x+2].value += tree[x].add * (rx - m);
        }

        tree[x].add = 0;
        tree[x].assign = 0;
    }

    void add(int l, int r, ll v) {
        add(l, r, v, 0, 0, size);
    }

    void add(int l, int r, ll v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            tree[x].add += v;
            tree[x].value += (rx - lx) * v;
        } else {
            int m = (lx + rx) / 2;
            add(l, r, v, 2 * x + 1, lx, m);
            add(l, r, v, 2 * x + 2, m, rx);
            tree[x].value = tree[2*x+1].value + tree[2*x+2].value;
        }
    }

    void assign(int l, int r, ll v) {
        assign(l, r, v, 0, 0, size);
    }

    void assign(int l, int r, ll v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            tree[x].assign = v;
            tree[x].add = 0;
            tree[x].value = (rx - lx) * v;
        } else {
            int m = (lx + rx) / 2;
            assign(l, r, v, 2 * x + 1, lx, m);
            assign(l, r, v, 2 * x + 2, m, rx);
            tree[x].value = tree[2*x+1].value + tree[2*x+2].value;
        }
    }

    ll query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

    ll query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return tree[x].value;
        int m = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, m) + query(l, r, 2 * x + 2, m, rx);
    }
};

int main(void) {
    int n, q;
    cin >> n >> q;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    segtree st;
    st.build(t);

    int cmd, a, b, x;
    while (q--) {
        cin >> cmd >> a >> b;
        if (cmd == 1) {
            cin >> x;
            st.add(a - 1, b, x);
        } else if (cmd == 2) {
            cin >> x;
            st.assign(a - 1, b, x);
        } else { // cmd == 3
            cout << st.query(a - 1, b) << '\n';
        }
    }

    return 0;
}
