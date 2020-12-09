#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;

    cin >> n;

    vector<pair<int,int>> movies(n);

    for (auto& m: movies) {
        cin >> m.second >> m.first;
    }

    sort(movies.begin(), movies.end());

    int result = 1;
    int prev = 0;

    for (int i = 1; i < n; i++) {
        if (movies[i].second >= movies[prev].first) {
            result++;
            prev = i;
        }
    }

    cout << result << endl;

    return 0;
}
