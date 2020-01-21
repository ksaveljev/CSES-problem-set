#include <iostream>
#include <set>
using namespace std;

int main(void) {
    int n, tmp;
    set<int> nums;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        nums.insert(tmp);
    }

    cout << nums.size() << endl;

    return 0;
}
