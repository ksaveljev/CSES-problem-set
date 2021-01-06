#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m;
const int maxN = 1e3;
char field[maxN][maxN];
int counter[maxN][maxN];
pair<int,int> from[maxN][maxN];
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void bfs(vector<pair<int,int>> start) {
    queue<tuple<int,int,int>> q;
    for (auto s: start) {
        q.push({s.first, s.second, 0});
    }

    while (!q.empty()) {
        auto [r, c, t] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m || field[nr][nc] == '#') {
                continue;
            }

            if (counter[nr][nc] == -1) {
                counter[nr][nc] = t + 1;
                q.push({nr, nc, t+1});
            } else if (counter[nr][nc] > t + 1) {
                counter[nr][nc] = t + 1;
                q.push({nr, nc, t+1});
            }
        }
    }
}

int main(void) {
    cin >> n >> m;
    int si, sj;
    vector<pair<int,int>> monsters;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
            counter[i][j] = -1;
            from[i][j] = {-1, -1};

            if (field[i][j] == 'A') {
                si = i, sj = j, field[i][j] = '.';
            } else if (field[i][j] == 'M') {
                monsters.push_back({i, j});
                field[i][j] = '.';
                counter[i][j] = 0;
            }
        }
    }

    bfs(monsters);

    bool found = false;
    queue<tuple<int,int,int>> q;
    q.push({si, sj, 0});
    while (!q.empty()) {
        auto [r, c, t] = q.front();
        q.pop();

        if (r == 0 || c == 0 || r == n-1 || c == m-1) {
            found = true;
            string s = "";
            while (r != si || c != sj) {
                auto [pr, pc] = from[r][c];
                int dr = pr - r;
                int dc = pc - c;

                if (dr == -1) {
                    s += "D";
                }
                if (dr == 1) {
                    s += "U";
                }
                if (dc == -1) {
                    s += "R";
                }
                if (dc == 1) {
                    s += "L";
                }
                r = pr;
                c = pc;
            }
            cout << "YES" << endl;
            cout << s.size() << endl;
            reverse(s.begin(), s.end());
            cout << s << endl;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                continue;
            }

            if (field[nr][nc] == '.' && from[nr][nc] == make_pair(-1, -1)) {
                if (counter[nr][nc] == -1 || counter[nr][nc] > t + 1) {
                    q.push({nr, nc, t+1});
                    from[nr][nc] = {r, c};
                }
            }
        }

    }

    if (!found) {
        cout << "NO" << endl;
    }

    return 0;
}
