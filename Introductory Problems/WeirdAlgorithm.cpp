//Weird Algorithm - https://cses.fi/problemset/task/1068

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    ll n;
    cin >> n;
    while (n > 1) {
        cout << n << " ";
        n = (n & 1 ? 3*n + 1 : n / 2);
    }
    cout << 1 << endl;
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