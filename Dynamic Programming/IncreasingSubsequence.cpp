//Increasing Subsequence - https://cses.fi/problemset/task/1145

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> result;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(result.begin(), result.end(), a[i]);
        if (it == result.end()) {
            result.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }
    cout << result.size() << endl;
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