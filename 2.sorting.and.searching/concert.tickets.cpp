#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(void) {
    int n, m;
    int h;

    cin >> n >> m;

    set<pair<int,int>> s;

    for (int i = 0; i < n; i++) {
        cin >> h;
        s.insert({h, i});
    }

    while (m--) {
        cin >> h;
        auto it = s.lower_bound({h, 0});
        if (it == s.begin()) {
            if ((*it).first == h) {
                cout << h << endl;
                s.erase(it);
            } else {
                cout << -1 << endl;
            }
        } else {
            if ((*it).first == h) {
                cout << h << endl;
                s.erase(it);
            } else {
                --it;
                cout << (*it).first << endl;
                s.erase(it);
            }
        }
    }
}
