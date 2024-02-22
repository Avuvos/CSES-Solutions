//Subarray Divisibility - https://cses.fi/problemset/task/1662

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
    ll sum = 0, ans = 0;
    vector<int> cnt(n, 0);
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        sum = (sum + a[i]) % n;
        if (sum < 0) sum += n;
        ans += cnt[sum]++;
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