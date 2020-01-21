#include <iostream>
using namespace std;

typedef long long ll;

int main(void) {
    ll t, x, y;

    cin >> t;

    while (t--) {
        cin >> y >> x;

        ll m = max(x, y);
        ll skip = (m - 1) * (m - 1);

        if (skip % 2 == 0) {
            if (m > y) {
                skip += m;
                skip += m - y;
            } else {
                skip += x;
            }
        } else {
            if (m > x) {
                skip += m;
                skip += m - x;
            } else {
                skip += y;
            }
        }

        cout << skip << endl;
    }
}
