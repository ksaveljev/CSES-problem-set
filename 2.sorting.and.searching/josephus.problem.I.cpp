#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <list>
#include <cassert>
using namespace std;

#define ll long long
#define pb push_back
#define loop(a) for(int i = 0; i < a; i++)
#define loopv(i,a) for (int i = 0; i < a; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int maxN = 1e6;
int children[maxN];

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        children[i] = i + 1;
    }

    list<int> ch(children, children + n);
    bool remove = 1;
    while (!ch.empty()) {
        for (auto it = ch.begin(); it != ch.end(); ) {
            remove = !remove;

            if (!remove) {
                it++;
                continue;
            }

            cout << *it << " ";
            auto to_remove = it;
            it++;
            ch.erase(to_remove);
        }
    }

    return 0;
}
