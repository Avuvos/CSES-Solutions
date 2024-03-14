//Inversion Probability - https://cses.fi/problemset/task/1728

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

//sum of indicators, linearity of expected value
//E[ans] = E[sum of all pairs] = sum(E[pair]) = sum(P[pair])

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double pair_prob = 0;
            for (int x = 1; x <= a[i]; x++) {
                pair_prob += min(1.0, (x - 1) / (double) a[j]);
            }
            pair_prob *= (1 / (double) a[i]);
            ans += pair_prob;
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
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