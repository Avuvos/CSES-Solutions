//Finding a Centroid - https://cses.fi/problemset/task/2079

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

    vector<int> sz(n, 0);
    function<void(int, int)> dfs1 = [&](int u, int p) -> void {
        sz[u] = 1;
        for (auto &v: g[u]) {
            if (v == p) continue;
            dfs1(v, u);
            sz[u] += sz[v];
        }
    };
    dfs1(0, -1);

    function<int(int, int)> dfs2 = [&](int u, int p) -> int {
        for (auto &v: g[u]) {
            if (v == p) continue;
            if (2 * sz[v] > n) {
                return dfs2(v, u);
            }
        }
        return u;
    };

    cout << dfs2(0, -1) + 1 << endl;
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