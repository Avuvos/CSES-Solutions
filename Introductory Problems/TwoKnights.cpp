//Two Knights - https://cses.fi/problemset/task/1072

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    for (ll k = 1; k <= n; k++) {
        ll total = k * k * (k * k - 1) / 2;
        ll invalid = 4 * (k - 1) * (k - 2);
        cout << total - invalid << '\n';
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