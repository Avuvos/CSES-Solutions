//Binomial Coefficients - https://cses.fi/problemset/task/1079

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


const int MOD = 1e9 + 7;
const ll INF = 1e18;

const int N = 1e6 + 17;
ll fact[N];
ll invfact[N];

ll expo(ll a, ll b, ll m) {
    ll res = 1;
    if (b == 0) return res;
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

void precalc_factorials() {
    fact[0] = fact[1] = 1;
    invfact[0] = invfact[1] = 1;
    for (int i = 2; i < N; ++i) {
        fact[i] = (i * fact[i - 1]) % MOD;
        invfact[i] = inverse(fact[i], MOD);
    }
}

void solve() {
    int n;
    cin >> n;
    precalc_factorials();
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        ll numerator = fact[a];
        ll denominator = (invfact[b] * invfact[a - b]) % MOD;
        cout << (numerator * denominator) % MOD << endl;
    }
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