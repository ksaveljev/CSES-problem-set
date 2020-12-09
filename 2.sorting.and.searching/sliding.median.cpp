#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, k;
pair<int,int> mid = {-1, 0};
set<pair<int,int>> bottom, top;

void fix() {
    int m = 1 + bottom.size() + top.size();

    if (bottom.size() < (m-1)/2) {
        bottom.insert(mid);
        mid = *top.begin();
        top.erase(mid);
    }

    if (bottom.size() > (m-1)/2) {
        top.insert(mid);
        mid = *(--bottom.end());
        bottom.erase(mid);
    }
}

void add(pair<int,int> x) {
    if (mid.first == -1) {
        mid = x;
        return;
    }

    if (x < mid) {
        bottom.insert(x);
    } else {
        top.insert(x);
    }

    fix();
}

void remove(pair<int,int> x) {
    if (x == mid) {
        mid = *top.begin();
        top.erase(mid);
    } else if (x < mid) {
        bottom.erase(x);
    } else {
        top.erase(x);
    }

    fix();
}

int main(void) {
    cin >> n >> k;
    vector<int> x(n);

    if (k == 1) {
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            cout << x[i] << " ";
        }
        return 0;
    }

    for (int i = 0; i < k-1; i++) {
        cin >> x[i];
        add({x[i], i});
    }

    for (int i = k-1; i < n; i++) {
        cin >> x[i];
        add({x[i], i});
        cout << mid.first << " ";
        remove({x[i-k+1], i-k+1});
    }

    return 0;
}
