//Coin Combinations 2 - https://cses.fi/problemset/task/1636

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (auto &coin: coins) {
        for (int i = 1; i <= x; i++) {
            if (i - coin < 0) continue;
            dp[i] += dp[i - coin];
            dp[i] %= MOD;
        }
    }
    cout << dp[x] << endl;
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