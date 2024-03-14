//Distributing Apples - https://cses.fi/problemset/task/1716

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

ll expo(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        b >>= 1;
    }
    return res;
}

ll inverse(ll a, ll mod){
    return expo(a , mod-2 , mod);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> fact(n + m + 1, 1), invfact(n + m + 1, 1);
    for (int i = 2; i <= n + m; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
        invfact[i] = inverse(fact[i], MOD);
    }
    cout << ((fact[n - 1 + m] * invfact[m]) % MOD * invfact[n - 1 + m - m]) % MOD << endl;
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