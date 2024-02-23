//Apple Division - https://cses.fi/problemset/task/1623/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = INF;
    for (int mask = 0; mask < (1 << n); mask++) {
        ll s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                s1 += a[i];
            } else {
                s2 += a[i];
            }
        }
        ans = min(ans, abs(s1 - s2));
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