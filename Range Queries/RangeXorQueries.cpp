//Range Xor Queries - https://cses.fi/problemset/task/1650

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> prefix_xor(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        prefix_xor[i + 1] = prefix_xor[i] ^ x;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << (prefix_xor[r + 1] ^ prefix_xor[l])<< '\n';
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