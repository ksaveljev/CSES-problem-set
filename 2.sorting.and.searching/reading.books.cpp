#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(void) {
    int n;

    cin >> n;

    vector<ll> books(n);
    ll sum = 0;

    for (ll& x: books) {
        cin >> x;
        sum += x;
    }

    sort(books.begin(), books.end());

    cout << max(sum, 2 * books[n-1]) << endl;

    return 0;
}
