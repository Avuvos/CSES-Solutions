//Flight Routes Check - https://cses.fi/problemset/task/1682

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

    vector<int> d(n, -1), low(n, 0), scc(n, -1);
    vector<bool> stacked(n, false);
    stack<int> s;
    int ticks = 0, current_scc = 0;
    auto tarjan = [&](auto tarjan, int u) -> void {
        d[u] = low[u] = ticks++;
        s.push(u);
        stacked[u] = true;
        for (int& v : g[u]){
            if (d[v] == -1){
                tarjan(tarjan, v);
                low[u] = min(low[u], low[v]);
            }else if (stacked[v]){
                low[u] = min(low[u], low[v]);
            }
        }
        if (d[u] == low[u]){
            int v;
            do {
                v = s.top();
                s.pop();
                stacked[v] = false;
                scc[v] = current_scc;
            } while (u != v);
            current_scc++;
        }
    };

    for (int i = 0; i < n; i++) {
        if (d[i] == -1) {
            tarjan(tarjan, i);
        }
    }

    vector<bool> reachable(n, false);
    auto dfs = [&](auto dfs, int u) -> void {
        reachable[u] = true;
        for (auto &v: g[u]) {
            if (reachable[v]) continue;
            dfs(dfs, v);
        }
    };
    dfs(dfs, 0);

    int main_scc = scc[0];
    for (int i = 1; i < n; i++) {
        if (scc[i] != main_scc) {
            cout << "NO" << endl;
            int source = 0, target = i;
            if (reachable[target]) {
                swap(source, target);
            }
            cout << source + 1 << " " << target + 1 << endl;
            return;
        }
    }
    cout << "YES" << endl;

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