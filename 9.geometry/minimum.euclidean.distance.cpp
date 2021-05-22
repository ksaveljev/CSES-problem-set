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
#include <climits>
using namespace std;

#define ll long long
#define ull unsigned long long
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
};

ull distance(const P& a, const P& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ull minimum_distance(const vector<P>& points_by_x, const vector<P>& points_by_y) {
    int n = points_by_x.size();

    if (n <= 1) {
        return ULLONG_MAX / 2;
    }

    vector<P> left_by_x = vector<P>(points_by_x.begin(), points_by_x.begin() + n / 2);
    vector<P> right_by_x = vector<P>(points_by_x.begin() + n/2, points_by_x.end());
    vector<P> left_by_y, right_by_y;
    for (const P& p : points_by_y) {
        if (p.x < left_by_x.back().x || (p.x == left_by_x.back().x && p.y <= left_by_x.back().y)) {
            left_by_y.push_back(p);
        } else {
            right_by_y.push_back(p);
        }
    }

    ull d1 = minimum_distance(left_by_x, left_by_y);
    ull d2 = minimum_distance(right_by_x, right_by_y);
    ull d = min(d1, d2);

    vector<P> stripe;
    ll middle_x = left_by_x.back().x;
    for (const P& p : points_by_y) {
        if (d > (middle_x - p.x) * (middle_x - p.x) && (p.x - middle_x) * (p.x - middle_x) < d) {
            stripe.push_back(p);
        }
    }

    for (int i = 0; i < stripe.size(); i++) {
        for (int j = i + 1; j < stripe.size() && (stripe[j].y - stripe[i].y) * (stripe[j].y - stripe[i].y) < d; j++) {
            d = min(d, distance(stripe[i], stripe[j]));
        }
    }

    return d;
}

int main(void) {
    int n;
    cin >> n;

    vector<P> points_by_x(n);
    for (auto& x : points_by_x) {
        x.read();
    }

    vector<P> points_by_y = points_by_x;
    sort(points_by_x.begin(), points_by_x.end(), [](const P& a, const P& b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });

    sort(points_by_y.begin(), points_by_y.end(), [](const P& a, const P& b) {
        return a.y < b.y;
    });

    cout << minimum_distance(points_by_x, points_by_y) << endl;

    return 0;
}
