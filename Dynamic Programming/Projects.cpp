//Projects - https://cses.fi/problemset/task/1140

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<array<ll, 3>> events = vector<array<ll, 3>>(n);
    vector<ll> dp = vector<ll>(n + 1, -1);
    for (int i = 0; i < n; ++i) {
        cin >> events[i][1] >> events[i][0] >> events[i][2];
    }

    auto get_prev_index = [&](int idx) -> int {
        int l = 0, r = idx - 1, ans = -1;
        while (l <= r) {
            int m = l + (r - l)/2;
            if (events[m][0] < events[idx][1]) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    };

    sort(events.begin(), events.end());
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = max(dp[i], events[i][2] + dp[get_prev_index(i) + 1]);
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