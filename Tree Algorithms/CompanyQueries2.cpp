//Company Queries II - https://cses.fi/problemset/task/1688

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    vector<int> parent(n), depth(n, 0);
    function<void(int, int, int)> dfs = [&](int u, int p, int d) {
        parent[u] = p;
        depth[u] = d;
        for (auto &v: g[u]) {
            if (v == p) continue;
            dfs(v, u, d + 1);
        }
    };
    dfs(0, 0, 0);
    const int LOG = 25;
    vector<vector<int>> up(LOG, vector<int>(n));
    for (int i = 0; i < n; i++) {
        up[0][i] = parent[i];
    }
    for (int i = 1; i < LOG; i++) {
        for (int j = 0; j < n; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }

    auto lca = [&](int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        for (int k = LOG - 1; k >= 0; k--) {
            if (depth[u] - (1 << k) >= depth[v]) {
                u = up[k][u];
            }
        }

        if (u == v) {
            return u;
        }

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }
        return parent[u];
    };

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << lca(u, v) + 1 << '\n';
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