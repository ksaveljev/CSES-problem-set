#include <iostream>
#include <vector>
#include <functional>
using namespace std;

using ll = long long;

int main(void) {
    int n, q;
    cin >> n >> q;

    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    int start, end;
    vector<vector<pair<int,int>>> queries(n + 1);
    for (int i = 0; i < q; i++) {
        cin >> start >> end;
        queries[start].push_back({end, i});
    }

    vector<ll> contrib(n+1, 0);
    vector<ll> bit(n+1, 0);
    function<ll(int)> query = [&](int idx) {
        ll s = 0;
        while (idx > 0) {
            s += bit[idx];
            idx -= idx & -idx;
        }
        return s;
    };
    function<void(int,ll)> update = [&](int idx, ll val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    };

    vector<ll> pref(n+2, 0);
    for (int i = 0; i <= n; i++) {
        pref[i+1] = pref[i] + x[i];
    }

    vector<pair<int,int>> maxs;
    vector<ll> result(q);
    for (int i = n; i >= 1; i--) {
        while (!maxs.empty() && maxs.back().first <= x[i]) {
            maxs.pop_back();
            update(maxs.size() + 1, -contrib[maxs.size()]);
            contrib[maxs.size()] = 0;
        }

        int len = (maxs.empty() ? n + 1 : maxs.back().second) - i;
        contrib[maxs.size()] = (ll)len * x[i];
        update(maxs.size() + 1, (ll)len * x[i]);
        maxs.push_back({x[i], i});

        for (auto &qqq : queries[i]) {
            int L = 0;
            int R = maxs.size() - 1;
            int valid = -1;
            while (L <= R) {
                int M = L + (R - L) / 2;
                if (maxs[M].second <= qqq.first) {
                    valid = M;
                    R = M - 1;
                } else {
                    L = M + 1;
                }
            }

            ll sum1 = query(maxs.size() + 1) - query(valid + 1);
            ll sum2 = (ll)(qqq.first - maxs[valid].second + 1) * maxs[valid].first;
            ll pref_sub = pref[qqq.first+1] - pref[i];
            result[qqq.second] = sum1 + sum2 - pref_sub;
        }
    }

    for (ll r : result) {
        cout << r << "\n";
    }

    return 0;
}
