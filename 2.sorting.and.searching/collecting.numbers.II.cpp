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

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<int> nums(n+1), pos(n+1);
    rep (i, 1, n+1) {
        cin >> nums[i];
        pos[nums[i]] = i;
    }

    int result = 1;
    rep (i, 1, n+1) {
        if (pos[i] < pos[i-1]) {
            result++;
        }
    }

    int a, b;
    while (m--) {
        cin >> a >> b;

        int numa = nums[a], numb = nums[b];

        set<pair<int,int>> s;
        s.insert({numa-1, numa});
        s.insert({numb-1, numb});
        if (numa < n) s.insert({numa, numa+1});
        if (numb < n) s.insert({numb, numb+1});

        for (auto [a, b] : s) {
            if (pos[b] < pos[a]) result--;
        }

        swap(nums[a], nums[b]);
        swap(pos[numa], pos[numb]);

        for (auto [a, b] : s) {
            if (pos[b] < pos[a]) result++;
        }

        cout << result << "\n";
    }

    return 0;
}
