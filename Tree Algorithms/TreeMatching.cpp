//Tree Matching - https://cses.fi/problemset/task/1130

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<array<int, 2>> dp(n); //dp[u][0] - skip node u. dp[u][1] - take node u.
    auto dfs = [&](auto dfs, int u, int p) -> void {
        int take = 0, skip = 0;
        int sum_children = 0;
        for (auto &v: g[u]) {
            if (v == p) continue;
            dfs(dfs, v, u);
            sum_children += max(dp[v][0], dp[v][1]);
        }
        skip = sum_children;
        for (auto &v: g[u]) {
            if (v == p) continue;
            take = max(take, 1 + sum_children - max(dp[v][0], dp[v][1]) + dp[v][0]);
        }
        dp[u][0] = skip;
        dp[u][1] = take;
    };
    dfs(dfs, 0, -1);
    cout << max(dp[0][0], dp[0][1]) << endl;
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