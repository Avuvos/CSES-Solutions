//Counting Necklaces - https://cses.fi/problemset/task/2209

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

ll expo(ll a, ll b, ll m=MOD) {
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

ll inverse(ll a, ll mod=MOD) {
    return expo(a , mod-2 , mod);
}


//burnside's lemma

void solve() {
    ll n, m;
    cin >> n >> m;

    ll group_size = n;
    ll sum_of_fixed_pts = 0;

    //counting rotations
    for (int rotation = 0; rotation < n; rotation++) {
        sum_of_fixed_pts += expo(m, gcd(rotation, n));
        sum_of_fixed_pts %= MOD;
    }

    cout << (sum_of_fixed_pts * inverse(group_size)) % MOD << endl;
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