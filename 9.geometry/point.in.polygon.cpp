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

bool segment_contains(const P& a, const P& b, const P& c) {
    if (a.triangle(b, c) != 0) {
        return false;
    }

    if (c.x < min(a.x, b.x) || c.x > max(a.x, b.x) || c.y < min(a.y, b.y) || c.y > max(a.y, b.y)) {
        return false;
    }

    return true;
}

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<P> polygon(n);
    for (auto& x : polygon) {
        x.read();
    }

    while (m--) {
        P x;
        x.read();

        bool on_boundary = false;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;

            if (segment_contains(polygon[i], polygon[j], x)) {
                on_boundary = true;
                break;
            }

            if (min(polygon[i].x, polygon[j].x) <= x.x && max(polygon[i].x, polygon[j].x) > x.x) {
                if (polygon[i].x < polygon[j].x) {
                    if (polygon[i].triangle(x, polygon[j]) > 0) count++;
                } else {
                    if (polygon[j].triangle(x, polygon[i]) > 0) count++;
                }
            }
        }

        if (on_boundary) {
            cout << "BOUNDARY\n";
        } else if (count & 1) {
            cout << "INSIDE\n";
        } else {
            cout << "OUTSIDE\n";
        }
    }

    return 0;
}
