//Flight Discount - https://cses.fi/problemset/task/1195

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        g[u].emplace_back(v, c);
    }

    //dp[node][flag] = best dist to this node, if flag is on it means we used the coupon otherwise we did not.
    vector<array<ll, 2>> dp(n, {INF, INF});
    dp[0][0] = dp[0][1] = 0;

    priority_queue<tuple<ll, ll, ll>,vector<tuple<ll, ll, ll>>,greater<>> pq;
    pq.push(make_tuple(0, 0, 0)); //[dist, node, used]

    while (!pq.empty()) {
        auto [dist, node, used] = pq.top(); pq.pop();
        if (dp[node][used] != dist) continue;
        for (auto [nei, weight]: g[node]) {
            if (!used) {
                //can either use the coupon
                if (dp[node][used] + weight/2 < dp[nei][1]) {
                    dp[nei][1] = dp[node][used] + weight/2;
                    pq.push(make_tuple(dp[nei][1], nei, 1));
                }
                //or not use the coupon
                if (dp[node][used] + weight < dp[nei][0]) {
                    dp[nei][0] = dp[node][used] + weight;
                    pq.push(make_tuple(dp[nei][0], nei, 0));
                }
            } else {
                //already used the coupon so cannot use it again
                if (dp[node][used] + weight < dp[nei][1]) {
                    dp[nei][1] = dp[node][used] + weight;
                    pq.push(make_tuple(dp[nei][1], nei, 1));
                }
            }
        }
    }

    cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
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