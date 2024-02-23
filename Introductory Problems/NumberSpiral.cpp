//Number Spiral - https://cses.fi/problemset/task/1071

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    ll y, x;
    cin >> y >> x;
    ll ans;
    if (x > y) {
        ans = (x & 1 ? x*x - y + 1 : (x - 1)*(x - 1) + y);
    } else if (x < y) {
        ans = (y & 1 ? (y - 1)*(y - 1) + x : y*y - x + 1);
    } else {
        ans = x*x - x + 1;
    }
    cout << ans << endl;
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