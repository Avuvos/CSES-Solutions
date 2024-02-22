//Subarray Sums I - https://cses.fi/problemset/task/1660

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
    for (int right = 0, left = 0; right < n; right++) {
        sum += a[right];
        while (left < right && sum > x) {
            sum -= a[left++];
        }
        ans += (sum == x);
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