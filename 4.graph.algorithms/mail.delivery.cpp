#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int maxN = 1e5, maxM = 2e5;
int n, m;
int ev[maxM], eu[maxM];
bool used[maxM];
vector<int> adj[maxN];
int degree[maxN];
vector<int> result;

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < m; i++ ) {
        cin >> ev[i] >> eu[i];
        --ev[i], --eu[i];
        adj[ev[i]].push_back(i);
        adj[eu[i]].push_back(i);
        degree[ev[i]]++;
        degree[eu[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (degree[i] & 1) {
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
    } else {
        for (int x: result) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }


    return 0;
}
