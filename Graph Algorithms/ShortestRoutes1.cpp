//Shortest Routes I - https://cses.fi/problemset/task/1671

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

    vector<ll> ans = fast_dijkstra(0);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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