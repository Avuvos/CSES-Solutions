//Coin Collector - https://cses.fi/problemset/task/1686

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<pair<int, int>> edges(m);
    vector<vector<int>> g(n);
    for (int index = 0; index < m; index++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[index] = make_pair(u, v);
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

    for (int node = 0; node < n; node++) {
        if (d[node] == -1) {
            tarjan(tarjan, node);
        }
    }

    vector<set<int>> scc_graph(current_scc);
    vector<ll> sum_comp(current_scc, 0);
    vector<ll> dp(current_scc, 0);

    for (auto [u, v]: edges) {
        if (scc[u] == scc[v]) continue;
        scc_graph[scc[u]].insert(scc[v]);
    }

    for (int node = 0; node < n; node++) {
        sum_comp[scc[node]] += coins[node];
    }

    auto dfs = [&](auto dfs, int cur) -> void {
        dp[cur] = 0;
        for(auto nei: scc_graph[cur]) {
            if (dp[nei] == -1)  {
                dfs(dfs, nei);
            }
            dp[cur] = max(dp[cur], dp[nei]);
        }
        dp[cur] += sum_comp[cur];
    };

    for (int comp = 0; comp < current_scc; comp++) {
        dfs(dfs, comp);
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
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