//Distance Queries - https://cses.fi/problemset/task/1135

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> parent(n), dist(n, 0);
    function<void(int, int, int)> dfs = [&](int u, int p, int d) {
        parent[u] = p;
        dist[u] = d;
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

    auto get_lca = [&](int u, int v) -> int {
        if (dist[u] < dist[v]) {
            swap(u, v);
        }

        for (int i = LOG - 1; i >= 0; i--) {
            if (dist[u] - (1 << i) >= dist[v]) {
                u = up[i][u];
            }
        }

        if (u == v) {
            return u;
        }

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[i][u] != up[i][v]) {
                u = up[i][u];
                v = up[i][v];
            }
        }
        return parent[u];
    };

    auto get_dist = [&](int u, int v) -> int {
        return dist[u] + dist[v] - 2 * dist[get_lca(u, v)];
    };

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << get_dist(a, b) << '\n';
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