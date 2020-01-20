#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string input;

    getline(cin, input);

    int best = 1;
    int current = 1;
    char prev = input[0];

    for (int i = 1, sz = input.size(); i < sz; i++) {
        if (input[i] == prev) {
            current++;
        } else {
            if (current > best) {
                best = current;
            }
            current = 1;
            prev = input[i];
        }
    }

    if (current > best) {
        best = current;
    }

    cout << best << endl;

    return 0;
}
