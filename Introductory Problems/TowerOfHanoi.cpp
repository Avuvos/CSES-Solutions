//Tower of Hanoi - https://cses.fi/problemset/task/2165

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    auto dfs = [&](auto dfs, int n, int left, int mid, int right) -> void {
        if (n <= 0) {
            return;
        }
        dfs(dfs, n - 1, left, right ,mid);
        cout << left << " " << right << '\n';
        dfs(dfs, n - 1, mid, left, right);
    };
    cout << ((1 << n) - 1) << '\n';
    dfs(dfs, n, 1, 2, 3);
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