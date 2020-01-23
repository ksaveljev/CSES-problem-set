#include <iostream>
using namespace std;

int main(void) {
    int n;
    int a, b, tmpa, tmpb;

    cin >> n;

    while (n--) {
        cin >> tmpa >> tmpb;

        a = max(tmpa, tmpb);
        b = min(tmpa, tmpb);

        while (a > 0 && b > 0) {
            if (a - b > 1) {
                int tmp = (a - b) / 2;
                a -= 2 * tmp;
                b -= tmp;
            } else if (a - b == 1) {
                a -= 2;
                b -= 1;
            } else if (a - b == 0) {
                if (a % 3 == 0) {
                    a = b = 0;
                } else {
                    a = 1;
                    b = 0;
                }
            }
        }

        if (a == 0 && b == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
