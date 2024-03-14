//Creating Strings II - https://cses.fi/problemset/task/1715

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

ll expo(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}

ll inverse(ll a, ll mod) {
    return expo(a, mod - 2, mod);
}


void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> cnt(26, 0);
    for (auto &c: s) cnt[c - 'a']++;

    vector<ll> fact(n + 1, 1);
    vector<ll> inv(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
        inv[i] = inverse(fact[i], MOD);
    }

    ll ans = fact[n];
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        ans *= inv[cnt[i]];
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