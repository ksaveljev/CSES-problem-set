#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <list>
#include <cassert>
#include <climits>
using namespace std;

#define ll long long
#define pb push_back
#define loop(a) for(int i = 0; i < a; i++)
#define loopv(i,a) for (int i = 0; i < a; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

vector<pair<int,int>> moves;

void move(int from, int aux, int to, int n) {
    if (n == 1) {
        moves.push_back({from, to});
        return;
    }

    move(from, to, aux, n - 1);
    move(from, aux, to, 1);
    move(aux, from, to, n - 1);
}

int main(void) {
    int n;
    cin >> n;

    move(1, 2, 3, n);

    cout << moves.size() << endl;
    for (auto [a, b] : moves) {
        cout << a << " " << b << endl;
    }

    return 0;
}
