#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

typedef struct {
    int start;
    int end;
    ull value;
} project;

bool theTruthIsOutThere(const project& a, const project& b) {
    return a.end < b.end;
}

bool compare(const project& a, const project& b) {
    return b.start > a.end;
}

int find(const vector<project>& projects, int i) {
    for (int j = i-1; j >= 0; j--) {
        if (projects[j].end < projects[i].start) {
            return j;
        }
    }

    return -1;
}

int main(void) {
    int n;

    cin >> n;

    vector<project> projects(n);

    for (project& p : projects) {
        cin >> p.start >> p.end >> p.value;
    }

    sort(projects.begin(), projects.end(), theTruthIsOutThere);

    vector<ull> dp(n);

    dp[0] = projects[0].value;

    for (int i = 1; i < n; i++) {
        int j = lower_bound(projects.begin(), projects.end(), projects[i], compare) - projects.begin();
        j--;

        if (j == -1) {
            dp[i] = max(dp[i-1], projects[i].value);
        } else {
            dp[i] = max(dp[j] + projects[i].value, dp[i-1]);
        }
    }

    cout << dp[n-1] << endl;

    return 0;
}
