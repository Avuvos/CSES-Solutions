//Subarray Sums II - https://cses.fi/problemset/task/1661

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = 0, ans = 0;
    map<ll, ll> mp; //map sum to count of prefixes with that sum
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans += mp[sum - x];
        mp[sum]++;
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