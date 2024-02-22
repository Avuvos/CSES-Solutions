//Collecting Numbers - https://cses.fi/problemset/task/2216

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        a--;
        pos[a] = i;
    }
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        if (pos[i] > pos[i + 1])
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