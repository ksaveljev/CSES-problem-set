#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, q;
    cin >> n >> q;

    char c;
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            prefix[i][j] = (c == '*') + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
        }
    }

    int y1, x1, y2, x2;
    while (q--) {
        cin >> y1 >> x1 >> y2 >> x2;
        if (y1 > y2) swap(y1, y2);
        if (x1 > x2) swap(x1, x2);
        cout << prefix[y2][x2] + prefix[y1-1][x1-1] - prefix[y1-1][x2] - prefix[y2][x1-1] << '\n';
    }

    return 0;
}
