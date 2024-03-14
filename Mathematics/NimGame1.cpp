//Nim Game I - https://cses.fi/problemset/task/1730

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    int total_xor = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        total_xor ^= x;
    }
    cout << (total_xor == 0 ? "second" : "first") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}