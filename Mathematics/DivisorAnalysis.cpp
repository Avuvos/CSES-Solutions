//Divisor Analysis - https://cses.fi/problemset/task/2182

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MOD2 = MOD - 1;
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

ll inverse(ll a, ll mod) {
    return expo(a , mod - 2, mod);
}

void solve() {
    int n;
    cin >> n;
    ll num_divisors = 1;
    ll sum_of_divisors = 1;
    ll product_of_divisors = 1;
    ll num_divisors2 = 1;
    for (int i = 0; i < n; i++) {
        ll p, k;
        cin >> p >> k;

        num_divisors *= (k + 1);
        num_divisors %= MOD;

        sum_of_divisors *= ((expo(p, k + 1, MOD) - 1) * inverse(p - 1, MOD) % MOD);
        sum_of_divisors %= MOD;

        product_of_divisors = expo(product_of_divisors, k + 1, MOD) * expo(expo(p, k*(k+1)/2, MOD), num_divisors2, MOD);
        product_of_divisors %= MOD;

        num_divisors2 *= (k + 1);
        num_divisors2 %= MOD2;
    }


    cout << num_divisors << " " << sum_of_divisors << " " << product_of_divisors << endl;
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