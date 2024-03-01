//Game Routes - https://cses.fi/problemset/task/1681

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }

    vector<ll> dp(n, -1);
    dp[n - 1] = 1;
    auto dfs = [&](auto dfs, int u) -> ll {
        if (dp[u] != -1) {
            return dp[u];
        }
        ll ans = 0;
        for (auto &v: g[u]) {
            if (dp[v] == -1) {
                dfs(dfs, v);
            }
            ans = (ans + dp[v]) % MOD;
        }
        return dp[u] = ans;
    };
    cout << dfs(dfs, 0) << endl;
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