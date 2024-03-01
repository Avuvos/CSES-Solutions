//Mail Delivery - https://cses.fi/problemset/task/1691

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n);
    vector<int> degree(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].insert(v);
        g[v].insert(u);
        degree[u]++;
        degree[v]++;
    }

    vector<bool> seen(n, false);
    auto dfs = [&](auto dfs, int u) -> void {
        seen[u] = true;
        for (auto v: g[u]) {
            if (seen[v]) continue;
            dfs(dfs, v);
        }
    };
    dfs(dfs, 0);


    for (int i = 0; i < n; i++) {
        if ((!seen[i] && degree[i] > 0) || (degree[i] & 1)) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    vector<int> ans;
    vector<int> stk = {0};
    while (!stk.empty()) {
        int v = stk.back();
        if (degree[v] == 0) {
            ans.push_back(v);
            stk.pop_back();
        } else {
            int nei = *g[v].begin();
            degree[nei]--;
            degree[v]--;
            stk.push_back(nei);
            g[v].erase(nei);
            g[nei].erase(v);
        }
    }


    for (int i = 0; i <= m; i++) {
        cout << ans[i] + 1 << " \n"[i == m];
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