//Coin Collector - https://cses.fi/problemset/task/1686

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

const int MAXN = 100001;

vector<int> g[MAXN];
int d[MAXN], low[MAXN], scc[MAXN];
bool stacked[MAXN];
stack<int> s;
int ticks, current_scc;

void tarjan(int u){
    d[u] = low[u] = ticks++;
    s.push(u);
    stacked[u] = true;
    for (int& v : g[u]){
        if (d[v] == -1){
            tarjan(v);
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
}

vector<int> coins;
vector<unordered_set<int>> adj;
vector<pair<int, int>> edges;
vector<ll> sum_comp;
vector<ll> dp;

vector<bool> visible;

void dfs(int cur) {
    visible[cur] = true;
    for(auto neib : adj[cur]) {
        if (!visible[neib])  {
            dfs(neib);
        }
        dp[cur] = max(dp[cur], dp[neib]);
    }
    dp[cur] += sum_comp[cur];
}

//todo prettify this solution and make normal tarjan template

void solve() {
    int n, m;
    cin >> n >> m;
    coins = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    fill_n(stacked, n, false);
    fill_n(d, n, -1);
    fill_n(low, n, 0);
    fill_n(scc, n, -1);
    fill_n(g, n, vector<int>());

    for (int index = 0; index < m; index++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.emplace_back(u, v);
        g[u].push_back(v);
    }
    for (int node = 0; node < n; node++) {
        if (d[node] == -1) {
            tarjan(node);
        }
    }

    adj = vector<unordered_set<int>>(current_scc);
    sum_comp = vector<ll>(current_scc, 0);
    dp = vector<ll>(current_scc, 0);
    visible = vector<bool>(current_scc, false);

    for (auto [u, v]: edges) {
        if (scc[u] == scc[v]) continue;
        adj[scc[u]].insert(scc[v]);
    }

    for (int node = 0; node < n; node++) {
        sum_comp[scc[node]] += coins[node];
    }

    ll ans = 0;
    for (int comp = 0; comp < current_scc; comp++) {
        dfs(comp);
    }

    for (int index = 0; index < current_scc; index++) {
        ans = max(ans, dp[index]);
    }
    cout << ans << endl;
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