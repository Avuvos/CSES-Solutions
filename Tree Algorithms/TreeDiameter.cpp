//Tree Diameter - https://cses.fi/problemset/task/1131

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto dfs = [&](auto dfs, int u, int p) -> pair<int, int> {
        pair<int, int> ans = {0, 0};
        for (auto &v: g[u]) {
            if (v == p) continue;
            auto [depth, index] = dfs(dfs, v, u);
            if (1 + depth > ans.first) {
                ans = {1 + depth, index};
            }
        }
        if ((int)g[u].size() == 1 && u != 0) {
            ans.second = u;
        }
        return ans;
    };

    auto [val, index] = dfs(dfs, 0, -1);
    auto [val2, index2] = dfs(dfs, index, -1);

    cout << val2 << endl;
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