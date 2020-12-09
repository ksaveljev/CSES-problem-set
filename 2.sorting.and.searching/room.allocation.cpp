#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
using namespace std;

int main(void) {
    int n;
    int a, b;
    cin >> n;

    set<pair<int,int>> s;
    int room = 1;
    vector<int> result(n);

    vector<tuple<int,int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[i] = {b, a, i};
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        auto [b, a, idx] = v[i];
        auto it = s.upper_bound({a, 0});

        if (it == s.begin()) {
            result[idx] = room;
            s.insert({b, room});
            room++;
        } else {
            --it;
            int r = it->second;
            result[idx] = r;
            s.erase(it);
            s.insert({b, r});
        }
    }

    cout << room - 1 << endl;
    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}
