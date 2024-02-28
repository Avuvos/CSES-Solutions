//Reading Books - https://cses.fi/problemset/task/1631

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;


void solve() {
    int n;
    cin >> n;
    vector<int> time(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }
    ll mx = *max_element(time.begin(), time.end());
    ll sum = accumulate(time.begin(), time.end(), 0LL);
    cout << max(2 * mx, sum) << endl;
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