#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    int a, b;
    vector< pair<int, bool> > events;

    cin >> n;

    while (n--) {
        cin >> a >> b;
        events.push_back(make_pair(a, true));
        events.push_back(make_pair(b, false));
    }

    sort(events.begin(), events.end());

    int result = 0;
    int best = 0;

    for (int i = 0; i < events.size(); i++) {
        if (events[i].second) {
            result++;
            best = max(best, result);
        } else {
            result--;
        }
    }

    cout << best << endl;

    return 0;
}
