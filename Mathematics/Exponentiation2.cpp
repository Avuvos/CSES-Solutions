//Exponentiation II - https://cses.fi/problemset/task/1712

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

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    ll e = expo(b, c, MOD - 1);
    cout << (expo(a, e, MOD))<< '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}