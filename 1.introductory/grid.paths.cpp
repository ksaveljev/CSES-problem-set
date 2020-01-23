#include <iostream>
#include <string>
using namespace std;

string input;
char visited[7][7];
int steps = 0;
int result = 0;

void find_solutions(int row, int col, int prow, int pcol) {
    if (row == 6 && col == 0) {
        if (steps == 48) {
            result++;
        }
        return;
    }

    if (col == 0 && row + 1 < 7 && visited[row+1][col] == 1 && pcol == 1) {
        return;
    }

    if (col == 0 && row + 1 < 7 && row - 1 >= 0 && visited[row+1][col] == 0 && visited[row-1][col] == 0 && pcol == 1) {
        return;
    }

    if (row == 6 && col > 0 && visited[row][col-1] == 1 && prow == 5) {
        return;
    }

    if (row == 6 && col > 0 && col + 1 < 7 && visited[row][col-1] == 0 && visited[row][col+1] == 0 && prow == 5) {
        return;
    }

    if (col == 6 && row + 1 < 7 && visited[row+1][col] == 1 && pcol == 5) {
        return;
    }

    if (col == 6 && row + 1 < 7 && row - 1 >= 0 && visited[row+1][col] == 0 && visited[row-1][col] == 0 && pcol == 5) {
        return;
    }

    if (row == 0 && col + 1 < 7 && visited[row][col+1] == 1 && prow == 1) {
        return;
    }

    if (row == 0 && col + 1 < 7 && col - 1 >= 0 && visited[row][col-1] == 0 && visited[row][col+1] == 0 && prow == 1) {
        return;
    }

    if (row > 0 && visited[row-1][col] == 1 && col > 0 && col < 7 && visited[row][col-1] == 0 && visited[row][col+1] == 0 && prow == row+1) {
        return;
    }

    if (row + 1 < 7 && visited[row+1][col] == 1 && col > 0 && col < 7 && visited[row][col-1] == 0 && visited[row][col+1] == 0 && prow == row-1) {
        return;
    }

    if (col > 0 && visited[row][col-1] == 1 && row > 0 && row < 7 && visited[row-1][col] == 0 && visited[row+1][col] == 0 && pcol == col+1) {
        return;
    }

    if (col + 1 < 7 && visited[row][col+1] == 1 && row > 0 && row < 7 && visited[row-1][col] == 0 && visited[row+1][col] == 0 && pcol == col-1) {
        return;
    }

    visited[row][col] = 1;
    steps++;

    if (row - 1 >= 0 && visited[row-1][col] == 0 && (input[steps-1] == '?' || input[steps-1] == 'U')) {
        find_solutions(row-1, col, row, col);
    }
    if (row + 1 < 7 && visited[row+1][col] == 0 && (input[steps-1] == '?' || input[steps-1] == 'D')) {
        find_solutions(row+1, col, row, col);
    }
    if (col - 1 >= 0 && visited[row][col-1] == 0 && (input[steps-1] == '?' || input[steps-1] == 'L')) {
        find_solutions(row, col-1, row, col);
    }
    if (col + 1 < 7 && visited[row][col+1] == 0 && (input[steps-1] == '?' || input[steps-1] == 'R')) {
        find_solutions(row, col+1, row, col);
    }

    steps--;
    visited[row][col] = 0;
}

int main(void) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            visited[i][j] = 0;
        }
    }

    cin >> input;

    find_solutions(0, 0, 0, 0);

    cout << result << endl;

    return 0;
}
