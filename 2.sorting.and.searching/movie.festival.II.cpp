#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
using namespace std;

int main(void) {
    int n, k;

    cin >> n >> k;

    vector<array<int, 3>> movies(n);

    for (int i = 0; i < n; i++) {
        cin >> movies[i][1] >> movies[i][0];
        movies[i][2] = i;
    }

    sort(movies.begin(), movies.end());

    set<pair<int,int>> s;
    int result = 0;

    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound({movies[i][1] + 1, 0});

        if (it != s.begin()) {
            --it;
            s.erase(it);
        }

        if (s.size() < k) {
            s.insert({movies[i][0], movies[i][2]});
            result++;
        }
    }

    cout << result << endl;

    return 0;
}
