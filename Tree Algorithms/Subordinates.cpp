//Subordinates - https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }

    vector<int> dp(n, 0);
    auto dfs = [&](auto dfs, int u, int p) -> void {
        for (auto v: g[u]) {
            if (v == p) continue;
            dfs(dfs, v, u);
            dp[u] += 1 + dp[v];
        }
    };

    dfs(dfs, 0, -1);
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " \n"[i == n - 1];
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