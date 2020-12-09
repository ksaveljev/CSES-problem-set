#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, x;

    cin >> n >> x;

    vector<int> ch(n);

    for (int& x: ch) {
        cin >> x;
    }

    sort(ch.begin(), ch.end());

    int result = 0;

    int start = 0;
    int end = n - 1;

    while (end >= start) {
        result++;
        if (end == start) {
            end--;
        } else if (ch[end] + ch[start] > x) {
            end--;
        } else {
            start++;
            end--;
        }
    }

    cout << result << endl;

    return 0;
}
