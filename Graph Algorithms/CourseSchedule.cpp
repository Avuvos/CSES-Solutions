//Course Schedule - https://cses.fi/problemset/task/1679

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

    vector<int> order = topological_sort(g);

    if (order.size() < n) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << order[i] + 1 << " \n"[i == n - 1];
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