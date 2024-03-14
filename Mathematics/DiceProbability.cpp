//Dice Probability - https://cses.fi/problemset/task/1725

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

//P(Sn <= s)
vector<vector<double>> memo;

double P(int n, int s) {
    if (s >= 6 * n) {
        return 1;
    }
    if (s <= 0) {
        return 0;
    }
    if (n == 1) {
        return s / 6.0;
    }
    if (memo[n][s] != -1) {
        return memo[n][s];
    }
    double ans = 0;
    for (int d = 1; d <= 6; d++) {
        ans += (1.0 / 6.0) * P(n - 1, s - d);
    }
    return memo[n][s] = ans;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    memo = vector<vector<double>>(n + 1, vector<double>(7*n, -1.0));
    double ans = P(n, b) - P(n, a - 1);
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