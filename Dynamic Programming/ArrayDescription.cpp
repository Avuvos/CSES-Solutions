//Array Description - https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
    function<ll(int, int)> dfs = [&](int index, int last) -> ll {
        if (index >= n) {
            return 1;
        }
        if (last != 0 && a[index] != 0 && abs(a[index] - last) > 1) {
            return 0;
        }
        if (dp[index][last] != -1) {
            return dp[index][last];
        }
        if (a[index] != 0) {
            return dfs(index + 1, a[index]);
        }
        ll ans = 0;
        if (last != 0) {
            if (last < m) {
                ans += dfs(index + 1, last + 1);
            }
            if (last > 1) {
                ans += dfs(index + 1, last - 1);
            }
            ans += dfs(index + 1, last);
            ans %= MOD;
        } else {
            for (int x = 1; x <= m; x++) {
                ans += dfs(index + 1, x);
                ans %= MOD;
            }
        }
        return dp[index][last] = ans;
    };
    cout << dfs(0, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}