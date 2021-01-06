#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char field[1000][1000];
pair<int,int> from[1000][1000];

bool ok(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m && field[i][j] == '.';
}

string reconstruct(int i, int j) {
    string result = "";

    while (i != -1 && j != -1) {
        auto [fi, fj] = from[i][j];
        int di = fi - i, dj = fj - j;

        if (di == 1 && dj == 0) {
            result += "U";
        }

        if (di == -1 && dj == 0) {
            result += "D";
        }

        if (di == 0 && dj == -1) {
            result += "R";
        }

        if (di == 0 && dj == 1) {
            result += "L";
        }

        i = fi;
        j = fj;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main(void) {
    cin >> n >> m;

    pair<int,int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
            if (field[i][j] == 'A') {
                field[i][j] = '.';
                start = {i, j};
            }
            if (field[i][j] == 'B') {
                field[i][j] = '.';
                end = {i, j};
            }
        }
    }

    bool found = false;
    queue<pair<int,int>> q;
    q.push({start.first, start.second});
    field[start.first][start.second] = '#';
    from[start.first][start.second] = {-1, -1};
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == end.first && c == end.second) {
            found = true;
            cout << "YES" << endl;
            string steps = reconstruct(r, c);
            cout << steps.size() << endl;
            cout << steps << endl;
            break;
        }


        if (ok(r - 1, c)) {
            field[r-1][c] = '#';
            q.push({r-1,c});
            from[r-1][c] = {r, c};
        }

        if (ok(r + 1, c)) {
            field[r+1][c] = '#';
            q.push({r+1,c});
            from[r+1][c] = {r, c};
        }

        if (ok(r, c - 1)) {
            field[r][c-1] = '#';
            q.push({r,c-1});
            from[r][c-1] = {r, c};
        }

        if (ok(r, c + 1)) {
            field[r][c+1] = '#';
            q.push({r,c+1});
            from[r][c+1] = {r, c};
        }
    }

    if (!found) cout << "NO" << endl;
}
