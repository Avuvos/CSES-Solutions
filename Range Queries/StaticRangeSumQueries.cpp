//Static Range Sum Queries - https://cses.fi/problemset/task/1646

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> ps(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ps[i + 1] = ps[i] + x;
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << ps[r + 1] - ps[l] << '\n';
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