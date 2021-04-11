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
    int n, x;
    cin >> n;

    vector<int> nums(n+1);
    rep (i, 1, n+1) {
        cin >> x;
        nums[x] = i;
    }

    int cur = 1;
    int result = 1;
    rep (i, 1, n+1) {
        if (cur > nums[i])
            result++;
        cur = nums[i];
    }

    cout << result << endl;

    return 0;
}
