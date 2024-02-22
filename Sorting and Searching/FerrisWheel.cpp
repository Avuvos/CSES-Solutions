//Ferris Wheel - https://cses.fi/problemset/task/1090

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
    sort(a.begin(), a.end());
    int ans = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        if (left == right){
            ans++;
            break;
        }
        if (a[left] + a[right] <= x) {
            left++;
            right--;
        } else {
            right--;
        }
        ans++;
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