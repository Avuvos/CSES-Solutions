//Repetitions - https://cses.fi/problemset/task/1069

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    string s;
    cin >> s;
    int ans = 1, streak = 1;
    for (int i = 1; i < s.size(); i++) {
        streak = (s[i] == s[i - 1] ? streak + 1 : 1);
        ans = max(ans, streak);
    }
    cout << ans << endl;
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