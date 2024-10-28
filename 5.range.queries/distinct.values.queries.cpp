#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct segtree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, 0);
    }

    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }

    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
        } else {
            int m = (lx + rx) / 2;
            if (i < m) {
                update(i, v, 2 * x + 1, lx, m);
            } else {
                update(i, v, 2 * x + 2, m, rx);
            }
            tree[x] = tree[2*x+1] + tree[2*x+2];
        }
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return 0;
        } else if (lx >= l && rx <= r) {
            return tree[x];
        } else {
            int m = (lx + rx) / 2;
            return query(l, r, 2 * x + 1, lx, m) + query(l, r, 2 * x + 2, m, rx);
        }
    }
};

typedef struct {
    int l, r;
    int idx;
} query;

int main(void) {
    int n, q;
    cin >> n >> q;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end(), [](const query &a, const query &b) {
        if (a.r == b.r) {
            return a.l < b.l;
        }
        return a.r < b.r;
    });

    vector<int> result(q, 0);
    map<int, int> m;
    segtree st;
    st.init(n);

    for (int i = 0, j = 0; i < n; i++) {
        if (m.find(x[i]) != m.end()) {
            st.update(m[x[i]], 0);
        }
        m[x[i]] = i;
        st.update(i, 1);

        while (j < q && queries[j].r == i) {
            result[queries[j].idx] = st.query(queries[j].l, queries[j].r + 1);
            j++;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}
