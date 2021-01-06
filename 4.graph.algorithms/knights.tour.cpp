#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int dir[8][2] = { {-2,-1}, {-2,1}, {2,-1}, {2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2} };
int result[8][8];

bool valid(int row, int col) {
    return row >= 0 && col >= 0 && row < 8 && col < 8 && result[row][col] == 0;
}

int moves(int row, int col) {
    int m = 0;

    for (int i = 0; i < 8; i++) {
        int r = row + dir[i][0];
        int c = col + dir[i][1];
        m += valid(r, c);
    }

    return m;
}

bool dfs(int row, int col, int depth) {
    result[row][col] = depth + 1;
    if (depth == 63) {
        return true;
    }

    vector<tuple<int,int,int>> next_move;
    for (int i = 0; i < 8; i++) {
        int r = row + dir[i][0];
        int c = col + dir[i][1];
        if (valid(r, c)) {
            next_move.push_back({moves(r, c), r, c});
        }
    }

    sort(next_move.begin(), next_move.end());

    for (int i = 0; i < next_move.size(); i++) {
        auto [x, r, c] = next_move[i];
        if (dfs(r, c, depth + 1)) {
            return true;
        }
    }

    result[row][col] = 0;

    return false;
}

int main(void) {
    int x, y;

    cin >> x >> y;
    --x, --y;

    dfs(y, x, 0);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
