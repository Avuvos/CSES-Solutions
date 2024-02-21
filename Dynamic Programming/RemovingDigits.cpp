//Removing Digits - https://cses.fi/problemset/task/1637

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<ll> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int cur = i;
        while (cur > 0) {
            int digit = cur % 10;
            cur /= 10;
            dp[i] = min(dp[i], 1 + dp[i - digit]);
        }
    }
    cout << dp[n] << endl;
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