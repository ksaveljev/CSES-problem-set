#include <iostream>
using namespace std;

int main(void) {
    int n;

    cin >> n;

    cout << 0 << endl;
    for (int i = 2; i <= n; i++) {
        if (i == 1) {
            cout << 0 << endl;
        } else if (i == 2) {
            cout << 6 << endl;
        } else if (i == 3) {
            cout << 28 << endl;
        } else if (i == 4) {
            cout << 96 << endl;
        } else {
            long long limit = i * i - 1;
            long long count = limit * (1 + limit) / 2;

            // first column
            count -= (i - 2) * 2;
            count -= 1;

            // second column
            count -= (i - 2) * 3;
            count -= 1;

            // last column
            count -= (i - 2) * 2;
            count -= 1;

            // second to last column
            count -= (i - 2) * 3;
            count -= 1;

            // big rectangle in the middle
            count -= (i - 4) * (i - 2) * 4;

            // second to last row
            count -= (i - 4) * 2;

            cout << count << endl;
        }
    }

    return 0;
}
