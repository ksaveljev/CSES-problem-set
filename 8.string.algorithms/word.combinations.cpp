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

const int MOD = 1e9+7;

struct Trie {
    int N = 0;
    vector<vector<int>> next = vector<vector<int>>(1, vector<int>(26));
    vector<bool> terminal = vector<bool>(1, false);

    void insert(const string& s) {
        int node = 0;
        for (char c : s) {
            if (next[node][c - 'a'] == 0) {
                next.push_back(vector<int>(26));
                terminal.push_back(false);
                next[node][c - 'a'] = ++N;
            }
            node = next[node][c - 'a'];
        }
        terminal[node] = true;
    }
};

int main(void) {
    string input;
    cin >> input;

    int k;
    cin >> k;

    Trie trie;

    vector<string> words(k);
    for (auto& x : words) {
        cin >> x;
        trie.insert(x);
    }

    int n = input.size();
    vector<int> dp(n+1);

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        int node = 0;
        int len = 0;
        for (char c : input.substr(i)) {
            len++;
            node = trie.next[node][c-'a'];
            if (node == 0) break;
            if (trie.terminal[node]) {
                dp[i + len] = (dp[i + len] + dp[i]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}
