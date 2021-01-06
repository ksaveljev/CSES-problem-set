#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char field[1002][1002];

int main(void) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i+1][j+1];
        }
    }

    int result = 0;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (field[i][j] == '.') {

                result++;

                queue<pair<int,int>> q;
                q.push({i, j});
                field[i][j] = '#';

                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        if (field[r+dirs[k][0]][c+dirs[k][1]] == '.') {
                            field[r+dirs[k][0]][c+dirs[k][1]] = '#';
                            q.push({r+dirs[k][0], c+dirs[k][1]});
                        }
                    }
                }

            }
        }
    }

    cout << result << endl;

    return 0;
}
