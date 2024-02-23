//Coin Piles - https://cses.fi/problemset/task/1754

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    ll a, b;
    cin >> a >> b;
    ll d1 = 2*b - a;
    ll d2 = 2*a - b;
    bool ok = (d1 >= 0 && d1 % 3 == 0) && (d2 >= 0 && d2 % 3 == 0);
    cout << (ok ? "YES" : "NO") << endl;
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