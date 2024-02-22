//Maximum Subarray Sum - https://cses.fi/problemset/task/1643/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;

    //Classic Kadane's Algo
    ll ans = -INF, cur = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cur = max(cur + x, x);
        ans = max(ans, cur);
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