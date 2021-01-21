#include <iostream>
#include <vector>
using namespace std;

pair<int,int> best[1<<20];

int main(void) {
    int n, x;

    cin >> n >> x;

    vector<int> w(n);

    for (auto& wi: w) {
        cin >> wi;
    }

    best[0] = {1, 0};

    for (int mask = 1; mask < (1<<n); mask++) {
        best[mask] = {n+1, 0};
        for (int p = 0; p < n; p++) {
            if ((1 << p) & mask) {
                auto tmp = best[mask ^ (1 << p)];
                if (tmp.second + w[p] <= x) {
                    tmp.second = w[p] + tmp.second;
                } else {
                    tmp = {tmp.first + 1, w[p]};
                }
                best[mask] = min(best[mask], tmp);
            }
        }
    }

    cout << best[(1<<n)-1].first << endl;

    return 0;
}
