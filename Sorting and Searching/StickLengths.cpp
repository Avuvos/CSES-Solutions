//Stick Lengths - https://cses.fi/problemset/task/1074

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int median = (n & 1 ? a[n / 2] : (a[n / 2] + a[n / 2 - 1]) / 2);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - median);
    }
    cout << ans << endl;
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