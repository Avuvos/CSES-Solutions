//Cycle Finding - https://cses.fi/problemset/task/1197

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {u, v, w};
    }


    vector<int> parent(n, 0);
    bool has_cycle = false;
    int start = 0;
    auto bellman_ford = [&](int source) -> vector<ll> {
        vector<ll> d(n, INF);
        d[source] = 0;
        for (int iteration = 1; iteration <= n; iteration++) {
            for (auto &[u, v, w]: edges) {
                if (d[u] + w < d[v]) {
                    if (iteration == n) {
                        has_cycle = true;
                    }
                    d[v] = d[u] + w;
                    parent[v] = u;
                    start = v;
                }
            }
        }
        return d;
    };

    bellman_ford(0);

    if (!has_cycle) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        start = parent[start];
    }
    vector<int> cycle;
    int current = start;
    do {
        cycle.push_back(current);
        current = parent[current];
    } while (current != start);
    cycle.push_back(current);
    reverse(cycle.begin(), cycle.end());

    for (auto &node: cycle) {
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