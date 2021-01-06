#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int n, m;
int a, b;
map<int,vector<int>> connections;
map<int,bool> visited;
vector<pair<int,int>> result;

int main(void) {
    cin >> n >> m;

    while (m--) {
        cin >> a >> b;

        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    vector<int> from(n + 1);

    bool found = false;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        m = q.front();
        q.pop();

        if (m == n) {
            found = true;
            break;
        }

        for (auto c: connections[m]) {
            if (visited[c]) continue;
            visited[c] = true;
            q.push(c);
            from[c] = m;
        }
    }

    if (found) {
        vector<int> steps;

        steps.push_back(n);

        while (n != 1) {
            int p = from[n];
            steps.push_back(p);
            n = p;
        }

        reverse(steps.begin(), steps.end());

        cout << steps.size() << endl;
        for (auto step: steps) {
            cout << step << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
