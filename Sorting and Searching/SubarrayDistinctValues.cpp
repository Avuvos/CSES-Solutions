//Subarray Distinct Values - https://cses.fi/problemset/task/2428

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<int, int> counter;
    ll ans = 0;
    for (int left = 0, right = 0; right < n; right++) {
        counter[a[right]]++;
        while ((int)counter.size() > k) {
            if (--counter[a[left]] == 0) {
                counter.erase(a[left]);
            }
            left++;
        }
        ans += (right - left + 1);
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