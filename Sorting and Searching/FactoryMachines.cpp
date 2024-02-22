//Factory Machines - https://cses.fi/problemset/task/1620

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    auto ok = [&](ll time)-> bool {
        ll products = 0;
        for (int i = 0; i < n; i++) {
            products += time / a[i];
            if (products >= t) {
                return true;
            }
        }
        return products >= t;
    };

    ll left = 0, right = INF, ans = INF;
    while (left <= right) {
        ll mid = left + (right - left)/2;
        if (ok(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
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