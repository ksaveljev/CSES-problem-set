#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main(void) {
    ll n, sum;
    vector<int> a, b;

    cin >> n;

    sum = n * (1 + n) / 2;

    if (sum % 2 != 0) {
        cout << "NO" << endl;
    } else if (n == 3) {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 3 << endl;
        cout << 2 << endl;
        cout << "1 2" << endl;
    } else if ((n - 3) % 4 == 0) {
        a.push_back(3);
        b.push_back(1);
        b.push_back(2);

        for (int i = 4; i <= n; i += 4) {
            a.push_back(i);
            b.push_back(i+1);
            b.push_back(i+2);
            a.push_back(i+3);
        }

        cout << "YES" << endl;

        cout << a.size() << endl;
        for (int i = 0; i < a.size(); i++) {
            if (i > 0) cout << " ";
            cout << a[i];
        }
        cout << endl;

        cout << b.size() << endl;
        for (int i = 0; i < b.size(); i++) {
            if (i > 0) cout << " ";
            cout << b[i];
        }
        cout << endl;
    } else if (n % 4 == 0) {
        for (int i = 1; i <= n; i += 4) {
            a.push_back(i);
            b.push_back(i+1);
            b.push_back(i+2);
            a.push_back(i+3);
        }

        cout << "YES" << endl;

        cout << a.size() << endl;
        for (int i = 0; i < a.size(); i++) {
            if (i > 0) cout << " ";
            cout << a[i];
        }
        cout << endl;

        cout << b.size() << endl;
        for (int i = 0; i < b.size(); i++) {
            if (i > 0) cout << " ";
            cout << b[i];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }


    return 0;
}
