//Sum of Two Values - https://cses.fi/problemset/task/1640/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (mp.find(x - a) != mp.end()) {
            cout << mp[x - a] << " " << i << endl;
            return;
        }
        mp[a] = i;
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