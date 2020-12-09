#include <iostream>
#include <vector>
#include <set>
using namespace std;

pair<int,int> mid = {-1, -1};
long long sb = 0, st = 0;
set<pair<int,int>> bottom, top;

void fix() {
    int m = 1 + bottom.size() + top.size();

    if (bottom.size() < (m-1) / 2) {
        bottom.insert(mid);
        sb += mid.first;
        mid = *top.begin();
        top.erase(mid);
        st -= mid.first;
    }

    if (bottom.size() > (m-1) / 2) {
        top.insert(mid);
        st += mid.first;
        mid = *(--bottom.end());
        bottom.erase(mid);
        sb -= mid.first;
    }
}

void add(pair<int,int> x) {
    if (mid.first == -1) {
        mid = x;
        return;
    }

    if (x.first < mid.first) {
        bottom.insert(x);
        sb += x.first;
    } else {
        top.insert(x);
        st += x.first;
    }

    fix();
}

void remove(pair<int,int> x) {
    if (x == mid) {
        mid = *top.begin();
        st -= mid.first;
        top.erase(mid);
    } else if (x < mid) {
        sb -= x.first;
        bottom.erase(x);
    } else {
        st -= x.first;
        top.erase(x);
    }

    fix();
}

int main(void) {
    int n, k;

    cin >> n >> k;
    vector<int> nums(n);

    if (k == 1) {
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            cout << 0 << " ";
        }
        return 0;
    }

    for (int i = 0; i < k - 1; i++) {
        cin >> nums[i];
        add({nums[i], i});
    }

    for (int i = k - 1; i < n; i++) {
        cin >> nums[i];
        add({nums[i], i});
        cout << st - mid.first * top.size() + mid.first * bottom.size() - sb << " ";
        remove({nums[i-k+1], i-k+1});
    }

    return 0;
}
