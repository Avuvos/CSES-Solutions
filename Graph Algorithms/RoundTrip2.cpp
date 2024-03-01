//Round Trip II - https://cses.fi/problemset/task/1678

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

    int start = -1;
    vector<int> color(n, 0), parent(n, -1);
    auto dfs = [&](auto dfs, int u) -> bool {
        color[u] = 1;
        for (auto &v: g[u]) {
            if (color[v] == 2) continue;
            parent[v] = u;
            if (color[v] == 1) {
                start = u;
                return true;
            }
            if (dfs(dfs, v)) {
                return true;
            }
        }
        color[u] = 2;
        return false;
    };

    for (int i = 0; i < n; i++) {
        if (color[i] == 0 && dfs(dfs, i)) {
            int current = start;
            vector<int> cycle;-
            do {
                cycle.push_back(current);
                current = parent[current];
            } while (current != start);
            cycle.push_back(current);
            reverse(cycle.begin(), cycle.end());
            cout << cycle.size() << endl;
            for (auto &node: cycle) {
                cout << node + 1 << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;

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