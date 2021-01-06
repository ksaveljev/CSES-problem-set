#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<int> sz;

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }

    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(void) {
    int n, m;

    cin >> n >> m;
    vector<tuple<int,int,int>> edges;
    parent.resize(n);
    sz.resize(n);

    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        --a, --b;
        edges.push_back({c, a, b});
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i < n; i++) {
        make_set(i);
    }

    int taken = 0;
    long long result = 0;
    for (int i = 0; i < edges.size(); i++) {
        auto [c, a, b] = edges[i];
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            union_sets(a, b);
            taken++;
            result += c;
        }
    }

    if (taken == n - 1) {
        cout << result << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
