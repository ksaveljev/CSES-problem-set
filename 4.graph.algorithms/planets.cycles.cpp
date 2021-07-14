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
#include <cassert>
using namespace std;

#define ll long long
#define pb push_back
#define loop(a) for(int i = 0; i < a; i++)
#define loopv(i,a) for (int i = 0; i < a; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int n;
vector<int> dest;
vector<bool> visited;
vector<int> result;

int main(void) {
    cin >> n;
    dest.resize(n);
    visited.assign(n, false);
    result.assign(n, -1);

    loop (n) {
        cin >> dest[i];
        dest[i]--;
    }

    loop (n) {
        stack<int> st;
        int v = i;
        while (!visited[v]) {
            st.push(v);
            visited[v] = true;
            v = dest[v];
        }

        int cycle_start = v;
        int count = 0;

        if (result[v] == -1) {
            vector<int> tmp;
            while (!st.empty()) {
                count++;
                v = st.top();
                st.pop();
                tmp.push_back(v);
                if (v == cycle_start) {
                    for (auto x : tmp) result[x] = count;
                    break;
                }
            }
        } else {
            count = result[v];
        }

        while (!st.empty()) {
            v = st.top();
            st.pop();
            result[v] = ++count;
        }
    }

    loop (n) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
