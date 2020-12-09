#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n;

    cin >> n;

    vector<int> x(n);
    vector<int> idx(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        idx[i] = i - 1;

        while (idx[i] >= 0 && x[idx[i]] >= x[i]) {
            idx[i] = idx[idx[i]];
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << idx[i] + 1;
    }
    cout << endl;

    return 0;
}
