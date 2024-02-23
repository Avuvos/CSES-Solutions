//Bit Strings - https://cses.fi/problemset/task/1617

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

ll expo(ll a, ll b, ll mod) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    cout << expo(2, n, MOD) << endl;
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