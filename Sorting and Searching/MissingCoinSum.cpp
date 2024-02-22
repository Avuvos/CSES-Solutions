//Missing Coin Sum - https://cses.fi/problemset/task/2183

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

//We got all the numbers in the range [0,...,ans - 1], can we get ans?
//We can't get it only if the next number is too large, i.e (0 + a[i] > ans)
//Otherwise there exists x in [0,..,ans-1] such that x + a[i] = ans.

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (ans < a[i]) {
            break;
        }
        ans += a[i];
    }

    cout << ans << '\n';
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