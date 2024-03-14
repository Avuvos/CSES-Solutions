//Stick Game - https://cses.fi/problemset/task/1729

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> pile(k);
    for (int i = 0; i < k; i++) {
        cin >> pile[i];
    }
    sort(pile.begin(), pile.end());
    vector<int> dp(n + 1, false);
    dp[1] = true;
    cout << "W";
    for (int i = 2; i <= n; i++) {
        for (auto stick: pile) {
            if (i - stick < 0) break;
            dp[i] |= !dp[i - stick];
        }
        cout << (dp[i] ? "W" : "L");
    }
    cout << endl;
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