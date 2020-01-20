#include <iostream>
using namespace std;

int main(void) {
    int n, prev, tmp;
    long long count = 0;

    cin >> n >> prev;
    n--;

    while (n--) {
        cin >> tmp;
        if (tmp < prev) {
            count += prev - tmp;
        } else {
            prev = tmp;
        }
    }

    cout << count << endl;

    return 0;
}
