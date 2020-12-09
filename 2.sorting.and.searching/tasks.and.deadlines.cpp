#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(void) {
    int n;

    cin >> n;

    vector<pair<int,int>> tasks(n);

    for (auto& x: tasks) {
        cin >> x.first >> x.second;
    }

    sort(tasks.begin(), tasks.end());

    ll time = 0;
    ll result = 0;

    for (auto& x: tasks) {
        time += x.first;
        result += x.second - time;
    }

    cout << result << endl;

    return 0;
}
