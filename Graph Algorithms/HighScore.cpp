//High Score - https://cses.fi/problemset/task/1673

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e17;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {u, v, -w};
    }

    //annoying edge case
    if (n == 1) {
        cout << (all_of(edges.begin(), edges.end(), [&](array<int, 3>& edge) { return edge[2] >= 0; }) ? 0 : -1) << endl;
        return;
    }

    auto bellman_ford = [&](int source, int target) -> ll {
        vector<ll> d(n, INF);
        d[source] = 0;

        auto relax = [&](ll set_value) {
            for (int iter = 1; iter < n; iter++) {
                for (auto &[u, v, w]: edges) {
                    if (d[u] < INF && d[u] + w < d[v]) {
                        d[v] = (set_value == -INF ? set_value : d[u] + w);
                    }
                }
            }
        };

        //first iteration to find the shortest path
        relax(0);

        //second iteration to detect negative cycles
        relax(-INF);

        return d[target];
    };

    ll ans = bellman_ford(0, n - 1);
    cout << (ans != -INF ? -ans : -1) << endl;
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