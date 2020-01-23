#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string input;
    int chars[30];

    for (int i = 0; i < 30; i++ ) {
        chars[i] = 0;
    }

    cin >> input;

    for (int i = 0, sz = input.size(); i < sz; i++) {
        chars[input[i] - 'A']++;
    }

    int odd = 0;
    int odd_idx = -1;
    for (int i = 0; i < 30; i++ ) {
        if (chars[i] % 2 != 0) {
            odd++;
            odd_idx = i;
        }
    }

    if (odd > 1) {
        cout << "NO SOLUTION" << endl;
    } else {
        for (int i = 0; i < 30; i++) {
            if (i == odd_idx) {
                continue;
            }

            for (int j = 0; j < chars[i] / 2; j++) {
                cout << char('A' + i);
            }
        }

        if (odd == 1) {
            for (int j = 0; j < chars[odd_idx]; j++) {
                cout << char('A' + odd_idx);
            }
        }

        for (int i = 29; i >= 0; i--) {
            if (i == odd_idx) {
                continue;
            }

            for (int j = 0; j < chars[i] / 2; j++) {
                cout << char('A' + i);
            }
        }

        cout << endl;
    }

    return 0;
}
