//Round Trip - https://cses.fi/problemset/task/1669

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
        g[v].push_back(u);
    }
    int start = -1;
    vector<bool> seen(n, false);
    vector<int> next(n, -1);
    auto dfs = [&](auto dfs, int current, int prev) -> bool {
        seen[current] = true;
        for (auto &nei: g[current]) {
            if (nei == prev) continue;
            if (seen[nei]) {
                next[current] = nei;
                start = nei;
                return true;
            }
            next[current] = nei;
            if (dfs(dfs, nei, current)) {
                return true;
            }
        }
        return false;
    };
    for (int i = 0; i < n; i++) {
        if (!seen[i] && dfs(dfs, i, -1)) {
            vector<int> cycle;
            int current = start;
            do {
                cycle.push_back(current);
                current = next[current];
            }
            while (current != start);
            cycle.push_back(start);
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