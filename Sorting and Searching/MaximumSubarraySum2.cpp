//Maximum Subarray Sum II - https://cses.fi/problemset/task/1644

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> ps(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ps[i + 1] = ps[i] + x;

    }
    
    priority_queue<pair<ll, int>> pq;
    for (int i = a; i < b; i++) {
        pq.emplace(ps[i], i);
    }

    ll ans = -INF;
    for (int right = b, left = 0; right <= n || left <= n - a; right++, left++) {
        if (right <= n) {
            pq.emplace(ps[right], right);
        }
        while (pq.top().second < left + a) {
            pq.pop();
        }
        assert(!pq.empty());
        auto [max_sum, index] = pq.top();
        ans = max(ans, max_sum - ps[left]);
    }
    cout << ans << endl;
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