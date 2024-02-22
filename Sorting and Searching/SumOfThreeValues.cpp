//Sum of Three Values - https://cses.fi/problemset/task/1641

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        auto [val, idx] = a[i];
        int target = x - val;
        int l = i + 1, r = n - 1;
        while (l < r) {
            auto [l_val, l_idx] = a[l];
            auto [r_val, r_idx] = a[r];
            if (l_val + r_val == target) {
                cout << idx << " " << l_idx << " " << r_idx << endl;
                return;
            } else if (l_val + r_val > target) {
                r--;
            } else {
                l++;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
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