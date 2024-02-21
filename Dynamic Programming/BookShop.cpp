//Book Shop - https://cses.fi/problemset/task/1158

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1, 0);
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if (j - price[i] >= 0) {
                dp[j] = max(dp[j], pages[i] + dp[j - price[i]]);
            }
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