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

const int maxN = 1e6+5;
vector<int> divisors(maxN, 1);

int main(void) {
    int n;
    cin >> n;

    for (int i = 2; i < maxN; i++) {
        for (int j = i; j < maxN; j += i) {
            divisors[j]++;
        }
    }

    while (n--) {
        int x;
        cin >> x;
        cout << divisors[x] << endl;
    }

    return 0;
}
