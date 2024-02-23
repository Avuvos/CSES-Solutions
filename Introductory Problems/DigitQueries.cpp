//Digit Queries - https://cses.fi/problemset/task/2431

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    ll k;
    cin >> k;
    ll len = 1, start = 1, pow = 9;
    while (true) {
        ll amount = pow * len;
        if (amount < k || amount < 0) {
            k -= amount;
        } else {
            k -= 1;
            ll d = k / len;
            string num = to_string(start + d);
            cerr << num << endl;
            cout << num[k % len] << endl;
            break;
        }
        len++;
        start *= 10;
        pow *= 10;
    }
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