//Flight Routes - https://cses.fi/problemset/task/1196

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
    }

    typedef pair<ll, ll> PLL;
    typedef priority_queue<PLL, vector<PLL>, greater<>> min_priority_queue_PLL;
    auto fast_dijkstra = [&](int start) -> vector<priority_queue<ll>> {
        vector<priority_queue<ll>> distances(n);
        distances[start].push(0);

        min_priority_queue_PLL pq;
        pq.emplace(0, start);

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > distances[u].top()) continue;
            for (auto [v, w]: g[u]) {
                if (distances[v].size() < k || distances[v].top() > d + w) {
                    if (distances[v].size() >= k) distances[v].pop();
                    ll new_dist = d + w;
                    distances[v].push(new_dist);
                    pq.emplace(new_dist, v);
                }
            }
        }
        return distances;
    };

    vector<priority_queue<ll>> distances = fast_dijkstra(0);
    vector<ll> ans(k);
    for (int i = 0; i < k; i++) {
        ans[i] = distances[n - 1].top();
        distances[n - 1].pop();
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " \n"[i == k - 1];
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