#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    string input;
    vector<string> strings;

    cin >> input;

    sort(input.begin(), input.end());

    do {
        strings.push_back(input);
    } while (next_permutation(input.begin(), input.end()));

    cout << strings.size() << endl;
    for (int i = 0, sz = strings.size(); i < sz; i++) {
        cout << strings[i] << "\n";
    }

    return 0;
}
