#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

const ull INF = 1e18+5;

int main(void) {
    int n, m, q;

    cin >> n >> m >> q;

    vector<vector<int>> adj(n);
    vector<vector<ull>> distance(n, vector<ull>(n, INF));

    for (int i = 0; i < n; i++)
        distance[i][i] = 0;

    int a, b;
    ull c;
    while (m--) {
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        distance[a][b] = min(distance[a][b], c);
        distance[b][a] = min(distance[a][b], c);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    while (q--) {
        cin >> a >> b;
        --a, --b;
        if (distance[a][b] == INF) {
            cout << -1 << endl;
        } else {
            cout << distance[a][b] << endl;
        }
    }
}
