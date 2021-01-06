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

void dfs(int i) {
    queue<int> q;
    q.push(i);

    visited[i] = true;

    while (!q.empty()) {
        i = q.front();
        q.pop();

        for (auto connection: connections[i]) {
            if (!visited[connection]) {
                visited[connection] = true;
                q.push(connection);
            }
        }
    }
}

int main(void) {

    cin >> n >> m;

    while (m--) {
        cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    int first = -1;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            continue;
        }

        dfs(i);

        if (first == -1) {
            first = i;
        } else {
            result.push_back({first, i});
        }
    }

    cout << result.size() << endl;
    for (auto c: result) {
        cout << c.first << " " << c.second << endl;
    }

    return 0;
}
