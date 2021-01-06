#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int maxN = 1e5, maxM = 2e5;
int n, m;
int ev[maxM], eu[maxM];
vector<int> adj[maxN];
int indegree[maxN], outdegree[maxN];
bool used[maxM];
vector<int> result;

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> ev[i] >> eu[i];
        ev[i]--, eu[i]--;
        adj[ev[i]].push_back(i);
        indegree[eu[i]]++;
        outdegree[ev[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (indegree[i] + 1 != outdegree[i]) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        } else if (i == n - 1) {
            if (indegree[i] != outdegree[i] + 1) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        } else if (indegree[i] != outdegree[i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    stack<int> st;
    st.push(0);
    while (!st.empty()) {
        int v = st.top();
        if (adj[v].empty()) {
            result.push_back(v);
            st.pop();
        } else {
            int e = adj[v].back();
            adj[v].pop_back();
            if (!used[e]) {
                used[e] = true;
                st.push(ev[e]^eu[e]^v);
            }
        }
    }

    if (result.size() != m + 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    reverse(result.begin(), result.end());

    for (auto x: result) {
        cout << x + 1 << " ";
    }
    cout << endl;

    return 0;
}
