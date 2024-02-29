//Message Route - https://cses.fi/problemset/task/1667

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
    vector<int> dist(n, -1), parent(n, -1);
    queue<int> q({0});
    dist[0] = 0;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (auto &nei: g[node]) {
            if (dist[nei] == -1) {
                dist[nei] = 1 + dist[node];
                q.push(nei);
                parent[nei] = node;
            }
        }
    }

    if (dist[n - 1] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> ans;
    int current = n - 1;
    while (current != -1) {
        ans.push_back(current);
        current = parent[current];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto node: ans) {
        cout << node + 1 << " ";
    }
    cout << endl;
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