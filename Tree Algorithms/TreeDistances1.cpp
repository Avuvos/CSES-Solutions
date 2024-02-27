//Tree Distances I - https://cses.fi/problemset/task/1132

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<array<int, 4>> dp(n, {0, 0, 0, 0});
    vector<int> ans(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    function <void(int, int)> dfs1 = [&](int u, int p) {
        for (auto &v: g[u]) {
            if (v == p) continue;
            dfs1(v, u);
        }
        for (auto &v: g[u]) {
            if (v == p) continue;
            if (1 + dp[v][0] >= dp[u][0]) {
                dp[u][2] = dp[u][0];
                dp[u][3] = dp[u][1];
                dp[u][0] = 1 + dp[v][0];
                dp[u][1] = v;
            } else if (1 + dp[v][0] >= dp[u][2]) {
                dp[u][2] = 1 + dp[v][0];
                dp[u][3] = v;
            }
        }
    };
    function <void(int, int)> dfs2 = [&](int u, int p) {
        int max_depth = dp[u][0];
        if (p != -1) {
            int parent_max_depth = 0;
            if (dp[p][1] != u) parent_max_depth = dp[p][0];
            else if (dp[p][3] != u) parent_max_depth = dp[p][2];
            if (1 + parent_max_depth > dp[u][0]) {
                dp[u][2] = dp[u][0];
                dp[u][3] = dp[u][1];
                dp[u][0] = 1 + parent_max_depth;
                dp[u][1] = p;
            } else if (1 + parent_max_depth > dp[u][2]) {
                dp[u][2] = 1 + parent_max_depth;
                dp[u][3] = p;
            }
            max_depth = max(max_depth, 1 + parent_max_depth);
        }
        ans[u] = max_depth;
        for (auto &v: g[u]) {
            if (v == p) continue;
            dfs2(v, u);
        }
    };

    dfs1(0, -1);
    dfs2(0, -1);

    for (int node = 0; node < n; node++) {
        cout << ans[node] << " \n"[node == n - 1];
    }
    
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