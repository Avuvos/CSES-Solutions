//Investigation - https://cses.fi/problemset/task/1202

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
    }

    typedef pair<ll, ll> PII;
    typedef priority_queue<PII, vector<PII>, greater<>> min_priority_queue_PII;
    auto fast_dijkstra = [&](int start) -> vector<ll> {
        vector<ll> dist(n, INF);
        min_priority_queue_PII pq;
        pq.push(make_pair(0, start));
        dist[start] = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (dist[u] != d) continue;// we just left it in pq until now instead of delete when we updated dist[u].
            for (auto [v, w]: g[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        return dist;
    };

    // Note: if there is a cycle, the size of the return will be less than n.
    // topsort template of neal wu
    auto topological_sort = [&] (const vector<vector<int>> &adj) -> vector<int> {
        int n = (int) adj.size();
        vector<int> in_degree(n, 0);
        vector<int> order;

        for (int i = 0; i < n; i++) {
            for (int neighbor : adj[i]) {
                in_degree[neighbor]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) {
                order.push_back(i);
            }
        }

        int current = 0;
        while (current < (int) order.size()) {
            int node = order[current++];
            for (int neighbor : adj[node]) {
                if (--in_degree[neighbor] == 0) {
                    order.push_back(neighbor);
                }
            }
        }
        return order;
    };


    vector<ll> min_dist = fast_dijkstra(0);

    //build sp graph
    vector<vector<int>> sp_g(n);
    for (int u = 0; u < n; u++) {
        for (auto &[v, w]: g[u]) {
            if (min_dist[u] + w == min_dist[v]) {
                sp_g[u].push_back(v);
            }
        }
    }

    vector<int> order = topological_sort(sp_g);

    vector<array<ll, 3>> dp(n); // [cnt sssp, min edges, max edges]
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for (int i = 1; i < n; i++) {
        dp[i][1] = n + 17;
        dp[i][2] = 0;
    }

    for (auto u: order) {
        for (auto v: sp_g[u]) {
            dp[v][0] = (dp[v][0] + dp[u][0]) % MOD;
            dp[v][1] = min(dp[v][1], dp[u][1] + 1);
            dp[v][2] = max(dp[v][2], dp[u][2] + 1);
        }
    }

    cout << min_dist[n - 1] << " " << dp[n - 1][0] << " " << dp[n - 1][1] << " " << dp[n - 1][2] << endl;
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