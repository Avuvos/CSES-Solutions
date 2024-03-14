//Candy Lottery - https://cses.fi/problemset/task/1727

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    double ans = 0;
    for (int value = 1; value <= k; value++) {
        if (value == 1) {
            ans += pow(1 / (double) k, n);
            continue;
        }
        double less_than_val = pow(value / (double) k, n);
        double less_than_val_minus_one = pow((value - 1) / (double) k, n);
        double prob = less_than_val - less_than_val_minus_one;
        ans += value * prob;
    }
    cout << setprecision(6) << fixed << ans << endl;
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