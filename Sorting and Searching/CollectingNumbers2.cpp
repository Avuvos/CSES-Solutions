//Collecting Numbers II - https://cses.fi/problemset/task/2217/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }

    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        if (pos[i] > pos[i + 1])
            ans++;
    }

    auto rebalance = [&](int x, int y, int delta) {
        int mn = min(x, y), mx = max(x, y);
        if (x < n - 1 && pos[x] > pos[x + 1]) ans += delta;
        if (y < n - 1 && pos[y] > pos[y + 1]) ans += delta;
        if (mn - 1 >= 0 && pos[mn - 1] > pos[mn]) ans += delta;
        if (mx - 1 != mn && pos[mx - 1] > pos[mx]) ans += delta;
    };

    for (int op = 0; op < m; op++) {
        int i, j;
        cin >> i >> j;
        i--, j--;
        int x = a[i], y = a[j];
        rebalance(x, y, -1);
        swap(pos[x], pos[y]);
        swap(a[i], a[j]);
        rebalance(x, y, 1);
        cout << ans << endl;
    }
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