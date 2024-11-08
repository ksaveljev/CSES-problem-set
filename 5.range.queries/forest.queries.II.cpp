#include <iostream>
#include <vector>
using namespace std;

struct segtree {
    int size;
    vector<vector<int>> tree;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, vector<int>(2 * size, 0));
        build_i(n, 0, 0, size);
    }

    void build_i(int n, int ix, int ilx, int irx) {
        if (irx - ilx == 1) {
            if (ilx < n) {
                build_j(n, ix, ilx, irx, 0, 0, size);
            }
        } else {
            int m = (ilx + irx) / 2;
            build_i(n, 2*ix+1, ilx, m);
            build_i(n, 2*ix+2, m, irx);
            build_j(n, ix, ilx, irx, 0, 0, size);
        }
    }

    void build_j(int n, int ix, int ilx, int irx, int jx, int jlx, int jrx) {
        if (jrx - jlx == 1) {
            if (jlx < n) {
                if (irx - ilx == 1) {
                    char c;
                    cin >> c;
                    if (c == '*') tree[ix][jx] = 1;
                    else tree[ix][jx] = 0;
                } else {
                    tree[ix][jx] = tree[2*ix+1][jx] + tree[2*ix+2][jx];
                }
            }
        } else {
            int m = (jlx + jrx) / 2;
            build_j(n, ix, ilx, irx, 2*jx+1, jlx, m);
            build_j(n, ix, ilx, irx, 2*jx+2, m, jrx);
            tree[ix][jx] = tree[ix][2*jx+1] + tree[ix][2*jx+2];
        }
    }

    void flip(int i, int j) {
        flip_i(i, j, 0, 0, size);
    }

    void flip_i(int i, int j, int ix, int ilx, int irx) {
        if (irx - ilx > 1) {
            int m = (ilx + irx) / 2;
            if (i < m) {
                flip_i(i, j, 2 * ix + 1, ilx, m);
            } else {
                flip_i(i, j, 2 * ix + 2, m, irx);
            }
        }
        flip_j(i, j, ix, ilx, irx, 0, 0, size);
    }

    void flip_j(int i, int j, int ix, int ilx, int irx, int jx, int jlx, int jrx) {
        if (jrx - jlx == 1) {
            if (irx - ilx == 1) {
                tree[ix][jx] ^= 1;
            } else {
                tree[ix][jx] = tree[2*ix+1][jx] + tree[2*ix+2][jx];
            }
        } else {
            int m = (jlx + jrx) / 2;
            if (j < m) {
                flip_j(i, j, ix, ilx, irx, 2 * jx + 1, jlx, m);
            } else {
                flip_j(i, j, ix, ilx, irx, 2 * jx + 2, m, jrx);
            }
            tree[ix][jx] = tree[ix][2*jx+1] + tree[ix][2*jx+2];
        }
    }

    int query(int y1, int x1, int y2, int x2) {
        return query_i(y1, x1, y2, x2, 0, 0, size);
    }

    int query_i(int y1, int x1, int y2, int x2, int ix, int ilx, int irx) {
        if (ilx >= y2 || irx <= y1) return 0;
        if (ilx >= y1 && irx <= y2) return query_j(y1, x1, y2, x2, ix, 0, 0, size);
        int m = (ilx + irx) / 2;
        return query_i(y1, x1, y2, x2, 2*ix+1, ilx, m) + query_i(y1, x1, y2, x2, 2*ix+2, m, irx);
    }

    int query_j(int y1, int x1, int y2, int x2, int ix, int jx, int jlx, int jrx) {
        if (jlx >= x2 || jrx <= x1) return 0;
        if (jlx >= x1 && jrx <= x2) return tree[ix][jx];
        int m = (jlx + jrx) / 2;
        return query_j(y1, x1, y2, x2, ix, 2*jx+1, jlx, m) + query_j(y1, x1, y2, x2, ix, 2*jx+2, m, jrx);
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0) ;

    int n, q;
    cin >> n >> q;

    segtree st;
    st.init(n);

    int cmd;
    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            int y, x;
            cin >> y >> x;
            st.flip(y - 1, x - 1);
        } else { // cmd == 2
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << st.query(y1 - 1, x1 - 1, y2, x2) << '\n';
        }
    }

    return 0;
}
