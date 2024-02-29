//Shortest Routes II - https://cses.fi/problemset/task/1672

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> g(n);
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        d[u][v] = min(d[u][v], (ll) w);
        d[v][u] = min(d[v][u], (ll) w);
    }

    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] < INF && d[k][j] < INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        ll ans = d[u][v];
        cout << (ans < INF ? ans : -1) << '\n';
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