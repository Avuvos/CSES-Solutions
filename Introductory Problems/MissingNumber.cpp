//Missing Number - https://cses.fi/problemset/task/1083

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    int ans = n;
    for (int i = 1; i <= n - 1; i++) {
        int x;
        cin >> x;
        ans ^= x;
        ans ^= i;
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