#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
    int x, n, p;
    vector<int> result;

    cin >> x >> n;

    set<int> s;
    s.insert(0);
    s.insert(x);

    map<int,int> m;
    m[x] = 1;

    while (n--) {
        cin >> p;
        auto it = s.lower_bound(p);
        auto r = *it;
        --it;
        auto l = *it;
        s.insert(p);
        m[r-l]--;
        if (!m[r-l]) {
            m.erase(r-l);
        }
        m[r-p]++;
        m[p-l]++;
        result.push_back((--m.end())->first);
    }

    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}
