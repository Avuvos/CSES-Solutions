//Money Sums - https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

const int N = 1e5 + 2;
void solve() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<vector<bool>> dp(N, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        dp[0][i] = true;
    }
    dp[coins[0]][0] = true;

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i - coins[j] < 0) continue;
            dp[i][j] = dp[i][j] | (dp[i - coins[j]][j - 1]);
        }
    }

    vector<int> ans;
    for (int i = 1; i < N; i++) {
        if (dp[i][n - 1]) {
            ans.push_back(i);
        }
    }

    int m = (int) ans.size();
    cout << m << endl;
    for (int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[i == m - 1];
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