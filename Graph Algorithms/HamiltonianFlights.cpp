//Hamiltonian Flights - https://cses.fi/problemset/task/1690

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
    vector<vector<ll>> dp(1 << n, vector<ll>(n, 0)); //dp[mask][last]
    dp[(1 << 0)][0] = 1;
    for (int mask = 0; mask < (1 << n) - 1; mask++) {
        for (int last = 0; last < n; last++) {
            if (!((mask >> last) & 1)) continue;
            if (dp[mask][last] == 0) continue;
            for (auto &nei: g[last]) {
                if ((mask >> nei) & 1) continue;
                int next_mask = mask | (1 << nei);
                dp[next_mask][nei] = (dp[next_mask][nei] + dp[mask][last]) % MOD;
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << endl;
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