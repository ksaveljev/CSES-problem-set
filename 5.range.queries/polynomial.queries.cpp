#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

struct segtree {
    struct node {
        ll a;
        ll d;
        ll sum;
    };
    int size;
    vector<node> tree;

    void build(const vector<int> &v) {
        size = 1;
        while (size < v.size()) size *= 2;
        tree.assign(2 * size, {0, 0, 0});
        build(v, 0, 0, size);
    }

    void build(const vector<int> &v, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            if (lx < v.size()) {
                tree[x] = {0, 0, v[lx]};
            }
        } else {
            int m = (lx + rx) / 2;
            build(v, 2 * x + 1, lx, m);
            build(v, 2 * x + 2, m, rx);
            tree[x].sum = tree[2*x+1].sum + tree[2*x+2].sum;
        }
    }

    void propagate(ll x, ll lx, ll rx) {
        if (tree[x].a == 0 && tree[x].d == 0 || rx - lx == 1) return;

        ll m = (lx + rx) / 2;

        tree[2*x+1].a += tree[x].a;
        tree[2*x+1].d += tree[x].d;
        tree[2*x+1].sum += tree[x].a * (m - lx) + tree[x].d * (m - lx) * (m - lx + 1) / 2;

        tree[2*x+2].a += tree[x].a + tree[x].d * (m - lx);
        tree[2*x+2].d += tree[x].d;
        tree[2*x+2].sum += tree[x].a * (rx - m) + tree[x].d * (rx - m) * (rx - m + 1) / 2 + tree[x].d * (m - lx) * (rx - m);

        tree[x].a = 0;
        tree[x].d = 0;
    }

    void update(ll l, ll r) {
        update(l, r, 0, 0, size);
    }

    void update(ll l, ll r, ll x, ll lx, ll rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            tree[x].a += lx - l;
            tree[x].d += 1;
            tree[x].sum += (lx - l) * (rx - lx) + (rx - lx) * (rx - lx + 1) / 2;
        } else {
            ll m = (lx + rx) / 2;
            update(l, r, 2*x+1, lx, m);
            update(l, r, 2*x+2, m, rx);
            tree[x].sum = tree[2*x+1].sum + tree[2*x+2].sum;
        }
    }

    ll sum(ll l, ll r) {
        return sum(l, r, 0, 0, size);
    }

    ll sum(ll l, ll r, ll x, ll lx, ll rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return tree[x].sum;
        ll m = (lx + rx) / 2;
        return sum(l, r, 2*x+1, lx, m) + sum(l, r, 2*x+2, m, rx);
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

    int cmd, a, b;
    while (q--) {
        cin >> cmd >> a >> b;
        a--;
        if (cmd == 1) {
            st.update(a, b);
        } else { // cmd == 2
            cout << st.sum(a, b) << '\n';
        }
    }

    return 0;
}
