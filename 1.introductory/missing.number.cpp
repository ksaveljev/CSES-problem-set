#include <iostream>
using namespace std;

int main(void) {
    int n, tmp;
    int nums[200001] = { 0 };

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> tmp;
        nums[tmp]++;
    }

    for (int i = 1; i <= n; i++) {
        if (nums[i] == 0) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
