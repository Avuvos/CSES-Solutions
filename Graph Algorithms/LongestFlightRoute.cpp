//Longest Flight Route - https://cses.fi/problemset/task/1680

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

    const int inf = 1e9 + 17;
    vector<int> dp(n, -inf);
    vector<int> nxt(n, -1);
    auto dfs = [&](auto dfs, int u) -> void {
        if (u == n - 1) {
            dp[u] = 0;
            return;
        }
        for (auto &v: g[u]) {
            if (dp[v] == -inf) {
                dfs(dfs, v);
            }
            if (dp[v] + 1 > dp[u]) {
                nxt[u] = v;
                dp[u] = max(dp[u], dp[v] + 1);
            }
        }
    };
    dfs(dfs, 0);

    if (dp[0] > 0) {
        cout << dp[0] + 1 << endl;
        int current = 0;
        while (current != n - 1) {
            cout << current + 1 << " ";
            current = nxt[current];
        }
        cout << current + 1 << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
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