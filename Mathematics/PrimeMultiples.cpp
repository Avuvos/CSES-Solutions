//Prime Multiples - https://cses.fi/problemset/task/2185

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> p(k);
    for (int i = 0; i < k; i++) {
        cin >> p[i];
    }
    ll ans = 0;
    for (int mask = 1; mask < (1LL << k); mask++) {
        ll mult = 1;
        int cnt = 0;
        for (int b = 0; b < k; b++) {
            if ((mask >> b) & 1) {
                if (mult > n / p[b]) {
                    mult = INF;
                    break;
                }
                mult *= p[b];
                cnt++;
            }
        }
        int sign = (cnt & 1 ? 1 : -1);
        ans += sign * (n / mult);
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