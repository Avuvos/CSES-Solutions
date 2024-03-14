//Bracket Sequences I - https://cses.fi/problemset/task/2064

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

ll expo(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll inverse(ll a, ll mod) {
    return expo(a, mod - 2, mod);
}

void solve() {
    int n;
    cin >> n;
    if (n & 1) {
        cout << 0 << endl;
        return;
    }
    n /= 2;
    vector<ll> fact(2*n + 1, 1);
    vector<ll> invfact(2*n + 1, 1);
    for (int i = 2; i <= 2*n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invfact[i] = inverse(fact[i], MOD);
    }
    cout << (((fact[2*n] * invfact[n]) % MOD) * invfact[n + 1]) % MOD << endl;
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