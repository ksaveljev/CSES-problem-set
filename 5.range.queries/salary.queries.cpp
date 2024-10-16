#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct Query {
    char t;
    int a, b;
};

struct segtree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, 0);
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
            tree[x] = tree[2*x+1] + tree[2*x+2];
        }
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return tree[x];
        int m = (lx + rx) / 2;
        return query(l, r, 2*x+1, lx, m) + query(l, r, 2*x+2, m, rx);
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<pair<int,int>> salaries;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        salaries.push_back({p[i], 0});
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].t >> queries[i].a >> queries[i].b;
        if (queries[i].t == '!') {
            salaries.push_back({queries[i].b, 0});
        } else {
            salaries.push_back({queries[i].a, 0});
            salaries.push_back({queries[i].b, 0});
        }
    }

    salaries.push_back({INT_MAX, 0});

    int idx = 0;
    sort(salaries.begin(), salaries.end());
    for (int i = 1; i < salaries.size(); i++) {
        if (salaries[i].first != salaries[i-1].first) {
            salaries[i].second = ++idx;
        } else {
            salaries[i].second = idx;
        }
    }

    segtree st;
    st.init(idx);

    for (int i = 0; i < n; i++) {
        st.update(lower_bound(salaries.begin(), salaries.end(), make_pair(p[i], 0))->second, 1);
    }

    for (auto query : queries) {
        if (query.t == '!') {
            st.update(lower_bound(salaries.begin(), salaries.end(), make_pair(p[query.a-1], 0))->second, -1);
            p[query.a - 1] = query.b;
            st.update(lower_bound(salaries.begin(), salaries.end(), make_pair(query.b, 0))->second, 1);
        } else {
            cout << st.query(
                lower_bound(salaries.begin(), salaries.end(), make_pair(query.a, 0))->second,
                upper_bound(salaries.begin(), salaries.end(), make_pair(query.b, INT_MAX))->second
            ) << '\n';
        }
    }

    return 0;
}
