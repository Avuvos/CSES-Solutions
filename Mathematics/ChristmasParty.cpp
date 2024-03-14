//Christmas Party - https://cses.fi/problemset/task/1717

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<ll> d(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        int sign = (i & 1 ? -1 : 1);
        d[i] = d[i - 1] * i + sign;
        d[i] %= MOD;
    }
    cout << d[n] << endl;
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