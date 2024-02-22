//Playlist - https://cses.fi/problemset/task/1141

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
    int ans = 0;
    set<int> s;
    for (int right = 0, left = 0; right < n; right++) {
        while (left < right && s.count(a[right])) {
            s.erase(a[left]);
            left++;
        }
        s.insert(a[right]);
        ans = max(ans, (int) s.size());
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