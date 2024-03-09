//Gray Code - https://cses.fi/problemset/task/2205

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;

    auto calc = [&](auto calc, int n) -> vector<string> {
        if (n == 1) {
            return {"0", "1"};
        }
        vector<string> prev_gray_code = calc(calc, n - 1);
        vector<string> current_gray_code;
        for (auto &s: prev_gray_code) {
            current_gray_code.push_back("0" + s);
        }
        reverse(prev_gray_code.begin(), prev_gray_code.end());
        for (auto &s: prev_gray_code) {
            current_gray_code.push_back("1" + s);
        }
        return current_gray_code;
    };

    vector<string> ans = calc(calc, n);
    for (auto &s: ans) {
        cout << s << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}