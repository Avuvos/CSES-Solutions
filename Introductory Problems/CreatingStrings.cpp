//Creating Strings - https://cses.fi/problemset/task/1622

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    string s;
    cin >> s;

    int cnt = 0;
    sort(s.begin(), s.end());
    do {
        cnt++;
    } while (next_permutation(s.begin(), s.end()));

    cout << cnt << '\n';
    do {
        cout << s << '\n';
    } while (next_permutation(s.begin(), s.end()));
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