//Sum of Divisors - https://cses.fi/problemset/task/1082

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

const ll TWO_INVERSE = 500000004;

void solve() {
    ll n;
    cin >> n;
    ll sq = (ll) sqrtl(n);
    ll ans = 0;

    for (ll d = 1; d <= n / (sq + 1); d++) {
        ans += ((d * (n / d)) % MOD);
        ans %= MOD;
    }

    auto f = [&](ll x) -> ll {
        x %= MOD;
        return (((x * (x + 1)) % MOD) * TWO_INVERSE) % MOD;
    };

    for (ll d = 1; d * d <= n; d++) {
        ll diff = (f(n / d) - f(n / (d + 1)) + MOD) % MOD;
        ans += (d * diff) % MOD;
        ans %= MOD;
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