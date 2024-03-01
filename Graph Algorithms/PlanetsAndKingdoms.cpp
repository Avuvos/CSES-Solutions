//Planets and Kingdoms - https://cses.fi/problemset/task/1683

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
    
    cout << current_scc << '\n';
    for (int i = 0; i < n; i++) {
        cout << scc[i] + 1 << " \n"[i == n - 1];
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