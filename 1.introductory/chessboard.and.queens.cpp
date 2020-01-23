#include <iostream>
#include <string>
using namespace std;

char board[8][8];
bool col[8], diag[16], diag2[16];
int result = 0;

void recur(int row) {
    if (row == 8) {
        result++;
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (!col[i] && !diag[row + i] && !diag2[row - i + 7] && board[row][i] != '*') {
            col[i] = true;
            diag[row + i] = true;
            diag2[row - i + 7] = true;
            recur(row + 1);
            col[i] = false;
            diag[row + i] = false;
            diag2[row - i + 7] = false;
        }
    }
}

int main(void) {
    string input;

    for (int i = 0; i < 8; i++) {
        col[i] = false;

        cin >> input;
        for (int j = 0; j < 8; j++) {
            board[i][j] = input[j];
        }
    }

    for (int i = 0; i < 16; i++) {
        diag[i] = false;
        diag2[i] = false;
    }

    recur(0);

    cout << result << endl;

    return 0;
}
