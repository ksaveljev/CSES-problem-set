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

bool intersect(const P& p1, const P& p2, const P& p3, const P& p4) {
    if ((p2 - p1) * (p4 - p3) == 0) {
        if (p1.triangle(p2, p3) != 0) {
            return false;
        }

        if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
            return false;
        }

        if (min(p1.x, p2.x) > max(p3.x, p4.x) || min(p1.y, p2.y) > max(p3.y, p4.y)) {
            return false;
        }
    } else {
        ll a = p1.triangle(p3, p2);
        ll b = p1.triangle(p4, p2);

        if ((a < 0 && b < 0) || (a > 0 && b > 0)) {
            return false;
        }

        ll c = p3.triangle(p1, p4);
        ll d = p3.triangle(p2, p4);

        if ((c < 0 && d < 0) || (c > 0 && d > 0)) {
            return false;
        }
    }

    return true;
}

int main(void) {
    P p1, p2, p3, p4;

    int t;
    cin >> t;

    while (t--) {
        p1.read();
        p2.read();
        p3.read();
        p4.read();

        if (intersect(p1, p2, p3, p4)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
