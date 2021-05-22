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

struct P {
    ll x, y;

    void read() {
        cin >> x >> y;
    }

    P operator -(const P& other) const {
        return { x - other.x, y - other.y };
    }

    void operator -=(const P& other) {
        x -= other.x;
        y -= other.y;
    }

    ll operator *(const P& other) const {
        return x * other.y - y * other.x;
    }

    ll triangle(const P& a, const P& b) const {
        return (a - *this) * (b - *this);
    }
};

int main(void) {
    int n;
    cin >> n;

    vector<P> polygon(n);
    for (auto& x : polygon) {
        x.read();
    }

    ll area = 0;
    for (int i = 0; i < n; i++) {
        area += polygon[i] * polygon[(i+1)%n];
    }

    cout << abs(area) << endl;

    return 0;
}
