//Grid Paths - https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<vector<ll>> dp = vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0));
    dp[1][1] = (grid[0][0] != '*');
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '*') continue;
            dp[i + 1][j + 1] += dp[i][j + 1] + dp[i + 1][j];
            dp[i + 1][j + 1] %= MOD;
        }
    }
    cout << dp[n][n] % MOD << endl;
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