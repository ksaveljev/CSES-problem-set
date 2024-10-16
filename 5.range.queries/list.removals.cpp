#include <iostream>
#include <vector>
using namespace std;

struct segtree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, 0);
        build(n, 0, 0, size);
    }

    void build(int n, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < n) tree[x] = 1;
        } else {
            int m = (lx + rx) / 2;
            build(n, 2 * x + 1, lx, m);
            build(n, 2 * x + 2, m, rx);
            tree[x] = tree[2*x+1] + tree[2*x+2];
        }
    }

    int query(int p) {
        return query(p, 0, 0, size);
    }

    int query(int p, int x, int lx, int rx) {
        if (tree[x] < p) return -1;
        if (rx - lx == 1) return lx;
        int m = (lx + rx) / 2;
        int res = query(p, 2 * x + 1, lx, m);
        if (res == -1) {
            res = query(p - tree[2*x+1], 2 * x + 2, m, rx);
        }
        return res;
    }

    void update(int idx, int v) {
        update(idx, v, 0, 0, size);
    }

    void update(int idx, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
        } else {
            int m = (lx + rx) / 2;
            if (idx < m) {
                update(idx, v, 2 * x + 1, lx, m);
            } else {
                update(idx, v, 2 * x + 2, m, rx);
            }
            tree[x] = tree[2*x+1] + tree[2*x+2];
        }
    }
};

int main(void) {
    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    segtree st;
    st.init(n);

    int p;
    for (int i = 0; i < n; i++) {
        cin >> p;
        int idx = st.query(p);
        st.update(idx, 0);
        if (i > 0) cout << " ";
        cout << x[idx];
    }
    cout << '\n';

    return 0;
}
