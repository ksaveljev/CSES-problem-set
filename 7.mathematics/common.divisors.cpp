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
int counter[maxN];

int main(void) {
    int n;
    cin >> n;

    int x;
    loop(n) {
        cin >> x;
        counter[x]++;
    }

    for (int gcd = 1e6; gcd >= 1; gcd--) {
        int d = 0;

        for (int j = gcd; j <= 1e6; j += gcd) d+= counter[j];

        if (d > 1) {
            cout << gcd << endl;
            break;
        }
    }

    return 0;
}
