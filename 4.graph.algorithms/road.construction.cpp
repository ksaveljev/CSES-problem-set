#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int msz;
vector<int> parent;
vector<int> sz;

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int get_parent(int v) {
    if (parent[v] == v) {
        return v;
    }

    return parent[v] = get_parent(parent[v]);
}

void join_set(int a, int b) {
    int pa = get_parent(a);
    int pb = get_parent(b);
    if (pa != pb) {
        if (sz[pa] < sz[pb]) {
            swap(pa, pb);
        }
        parent[pb] = pa;
        sz[pa] += sz[pb];
        n--;
        msz = max(msz, sz[pa]);
    }
}

int main(void) {
    cin >> n >> m;

    parent.resize(n);
    sz.resize(n);

    for (int i = 0; i < n; i++) {
        make_set(i);
    }

    int a,b;
    while (m--) {
        cin >> a >> b, --a, --b;

        join_set(a, b);

        cout << n << " " << msz << endl;
    }

    return 0;
}
