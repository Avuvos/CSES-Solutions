//Building Teams - https://cses.fi/problemset/task/1668

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> team(n, -1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto bfs = [&](int source) -> bool {
        queue<int> q({source});
        int t = 0;
        while (!q.empty()) {
            int sz = (int) q.size();
            for (int j = 0; j < sz; j++) {
                int node = q.front(); q.pop();
                team[node] = t;
                for (auto &nei: g[node]) {
                    if (team[nei] == team[node]) {
                        return false;
                    }
                    if (team[nei] == -1) {
                        q.push(nei);
                    }
                }
            }
            t ^= 1;
        }
        return true;
    };

    for (int i = 0; i < n; i++) {
        if (team[i] == -1 && !bfs(i)) {
            cout << "IMPOSSIBLE" << '\n';
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << team[i] + 1 << " \n"[i == n - 1];
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