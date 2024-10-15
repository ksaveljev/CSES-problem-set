#include <iostream>
#include <vector>
using namespace std;

struct segtree {
    int size;
    vector<int> tree;

    void build(vector<int> &v) {
        size = 1;
        while (size < v.size()) size *= 2;
        tree.assign(2 * size, 0);
        build(v, 0, 0, size);
    }

    void build(vector<int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < v.size()) {
                tree[x] = v[lx];
            }
        } else {
            int m = (lx + rx) / 2;
            build(v, 2 * x + 1, lx, m);
            build(v, 2 * x + 2, m, rx);
            tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }

    int query(int v) {
        return query(v, 0, 0, size);
    }

    int query(int v, int x, int lx, int rx) {
        if (tree[x] < v) {
            return -1;
        } else if (rx - lx == 1) {
            return lx;
        } else {
            int m = (lx + rx) / 2;
            int res = query(v, 2 * x + 1, lx, m);
            if (res == -1) {
                res = query(v, 2 * x + 2, m, rx);
            }
            return res;
        }
    }

    void update(int idx, int v) {
        update(idx, v, 0, 0, size);
    }

    void update(int idx, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] += v;
        } else {
            int m = (lx + rx) / 2;
            if (idx < m) {
                update(idx, v, 2 * x + 1, lx, m);
            } else {
                update(idx, v, 2 * x + 2, m, rx);
            }
            tree[x] = max(tree[2*x+1], tree[2*x+2]);
        }
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    segtree st;
    st.build(h);

    int r;
    for (int i = 0; i < m; i++) {
        if (i > 0) cout << " ";
        cin >> r;
        int idx = st.query(r);
        cout << idx + 1;
        if (idx >= 0) {
            st.update(idx, -r);
        }
    }
    cout << '\n';

    return 0;
}
