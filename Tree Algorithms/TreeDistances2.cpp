//Tree Distances II - https://cses.fi/problemset/task/1133

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<ll> dp(n, 0), sz(n, 0), ans(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    //calc the size and the distances for each subtree
    function<void(int, int)> dfs1 = [&](int u, int p) {
        sz[u] = 1;
        for (auto &v: g[u]) {
            if (v == p) continue;
            dfs1(v, u);
        }
        for (auto &v: g[u]) {
            if (v == p) continue;
            sz[u] += sz[v];
            dp[u] += (sz[v] + dp[v]);
        }
        ans[u] = dp[u];
    };

    function<void(int, int)> dfs2 = [&](int u, int p) {
        //update u to be the new root
        if (p != -1) {
            dp[p] -= (dp[u] + sz[u]);
            sz[p] -= sz[u];

            sz[u] += sz[p];
            dp[u] += (dp[p] + sz[p]);
            ans[u] += (dp[p] + sz[p]);
        }
        //re-root the children
        for (auto &v: g[u]) {
            if (v == p) continue;
            dfs2(v, u);
        }
        //return u to his previous place
        if (p != -1) {
            sz[u] -= sz[p];
            dp[u] -= (dp[p] + sz[p]);

            sz[p] += sz[u];
            dp[p] += (dp[u] + sz[u]);
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
    cin.tie(0);
    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}