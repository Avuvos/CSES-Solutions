//Graph Paths I - https://cses.fi/problemset/task/1724

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18 + 170;

vector<vector<ll>> matrix_mult(vector<vector<ll>>& A, vector<vector<ll>>& B) {
    int a_rows = (int) A.size(), a_cols = (int) A[0].size();
    int b_rows = (int) B.size(), b_cols = (int) B[0].size();
    assert(a_cols == b_rows);
    vector<vector<ll>> C(a_rows, vector<ll>(b_cols, INF));
    for (int i = 0; i < a_rows; i++) {
        for (int j = 0; j < b_cols; j++) {
            for (int k = 0; k < a_cols; k++) {
                if (A[i][k] == INF || B[k][j] == INF) continue;
                C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
            }
        }
    }
    return C;
}

vector<vector<ll>> matrix_expo(vector<vector<ll>>& A, ll b) {
    bool res_is_id = true;
    vector<vector<ll>> res;
    while (b > 0) {
        if (b & 1) {
            res = res_is_id ? A : matrix_mult(res, A);
            res_is_id = false;
        }
        A = matrix_mult(A, A);
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> adj(n, vector<ll>(n, INF));
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u][v] = min(adj[u][v], w);
    }
    ll ans = matrix_expo(adj, k)[0][n - 1];
    cout << (ans < INF ? ans : -1) << endl;
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