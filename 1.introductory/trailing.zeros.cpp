#include <iostream>
using namespace std;

typedef long long ll;

int main(void) {
    ll n;
    ll div = 5;
    ll result = 0;

    cin >> n;

    while (n / div > 0) {
        result += n / div;
        div *= 5;
    }

    cout << result;

    return 0;
}
