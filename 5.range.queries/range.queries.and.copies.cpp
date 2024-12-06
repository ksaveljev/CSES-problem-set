#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

struct Vertex {
    Vertex *left, *right;
    ll sum;

    Vertex(ll value): left(nullptr), right(nullptr), sum(value) {}
    Vertex(Vertex *left, Vertex *right) : left(left), right(right), sum(0) {
        if (left) sum += left->sum;
        if (right) sum += right->sum;
    }
};

Vertex *build(const vector<int> &v, int lx, int rx) {
    if (rx - lx == 1) {
        return new Vertex(v[lx]);
    }
    int m = (lx + rx) / 2;
    return new Vertex(build(v, lx, m), build(v, m, rx));
}

Vertex *update(Vertex *v, int idx, int val, int lx, int rx) {
    if (rx - lx == 1) {
        return new Vertex(val);
    }
    int m = (lx + rx) / 2;
    if (idx < m) {
        return new Vertex(update(v->left, idx, val, lx, m), v->right);
    } else {
        return new Vertex(v->left, update(v->right, idx, val, m, rx));
    }
}

ll query(Vertex *v, int l, int r, int lx, int rx) {
    if (lx >= r || rx <= l) return 0;
    if (lx >= l && rx <= r) return v->sum;
    int m = (lx + rx) / 2;
    return query(v->left, l, r, lx, m) + query(v->right, l, r, m, rx);
}

const int nax = 2e5 + 5;
Vertex *trees[nax];

int main(void) {
    int n, q;
    cin >> n >> q;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int idx = 1;
    trees[idx++] = build(t, 0, n);

    int cmd;
    while (q--) {
        cin >> cmd;

        if (cmd == 1) {
            int k, a, x;
            cin >> k >> a >> x;
            trees[k] = update(trees[k], a-1, x, 0, n);
        } else if (cmd == 2) {
            int k, a, b;
            cin >> k >> a >> b;
            cout << query(trees[k], a-1, b, 0, n) << "\n";
        } else { // cmd == 3
            int k;
            cin >> k;
            trees[idx++] = trees[k];
        }
    }

    return 0;
}
