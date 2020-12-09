#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <map>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> songs(n);
    for (int& s: songs) {
        cin >> s;
    }

    int result = 1;
    int best = 1;
    int start = 0;
    map<int,int> m;
    m[songs[0]] = 0;

    for (int i = 1; i < n; i++) {
        int x = songs[i];
        if (m.find(x) == m.end() || m[x] == -1) {
            result++;
            m[x] = i;
        } else {
            best = max(best, result);
            int new_start = m[x] + 1;

            for (int j = start; j < m[x]; j++) {
                result--;
                m[songs[j]] = -1;
            }

            m[x] = i;

            start = new_start;
        }
    }

    best = max(best, result);

    cout << best << endl;

    return 0;
}
