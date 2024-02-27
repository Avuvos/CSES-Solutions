//Company Queries I - https://cses.fi/problemset/task/1687

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

    auto get_kth_ancestor = [&](int u, int k) -> int {
        if (k > dist[u]) {
            return -1;
        }
        int v = u;
        for (int i = 0; i < LOG; i++) {
            if ((k >> i) & 1) {
                v = up[i][v];
            }
        }
        return v + 1;
    };

    for (int i = 0; i < q; i++) {
        int u, k;
        cin >> u >> k;
        u--;
        cout << get_kth_ancestor(u, k) << '\n';
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