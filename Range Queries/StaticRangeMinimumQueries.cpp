//Static Range Minimum Queries - https://cses.fi/problemset/task/1647

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

const int inf = 1e9 + 17;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto compute_log2 = [&](ll x) -> int {
        return x > 0 ? __builtin_clzll(1) - __builtin_clzll(x) : -1;
    };

    int k = compute_log2(n);
    vector<vector<int>> sparse_table(k + 1, vector<int>(n + 1, inf));
    for (int i = 0; i < n; i++) {
        sparse_table[0][i] = a[i];
    }

    //cp-algorithms code
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            sparse_table[i][j] = min(sparse_table[i - 1][j], sparse_table[i - 1][j + (1 << (i - 1))]);
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int lg = compute_log2(r - l + 1);
        cout << min(sparse_table[lg][l], sparse_table[lg][r - (1 << lg) + 1]) << '\n';
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