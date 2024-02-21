//Counting Numbers - https://cses.fi/problemset/task/2220

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

ll dp[20][11][2][2];

void solve() {
    ll a, b;
    cin >> a >> b;
    auto dfs = [&](auto dfs, string s, int index, int last, int tight, int zero) -> ll {
        if (index >= (int)s.size()) {
            return 1;
        }
        if (dp[index][last][tight][zero] != -1) {
            return dp[index][last][tight][zero];
        }
        int bound = (tight ? s[index] - '0' : 9);
        ll ans = 0;
        for (int digit = 0; digit <= bound; digit++) {
            if (digit == last && !zero) continue;
            ans += dfs(dfs, s, index + 1, digit, tight && (s[index] - '0') == digit, zero && digit == 0);
        }
        return dp[index][last][tight][zero] = ans;
    };

    memset(dp, -1, sizeof(dp));
    ll ansHigh = dfs(dfs, to_string(b), 0, 10, 1, 1);

    memset(dp, -1, sizeof(dp));
    ll ansLow = dfs(dfs, to_string(a - 1), 0, 10, 1, 1);

    cout << ansHigh - ansLow << endl;

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