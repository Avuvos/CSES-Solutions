//De Bruijn Sequence - https://cses.fi/problemset/task/1692

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    string ans;
    set<string> seen;
    auto dfs = [&](auto dfs, string& current) -> void {
        for (char c = '0'; c <= '1'; c++) {
            string next = current + c;
            if (seen.find(next) == seen.end()) {
                seen.insert(next);
                next = next.substr(1);
                dfs(dfs, next);
                ans.push_back(c);
            }
        }
    };
    string start = string(n - 1, '0');
    dfs(dfs, start);
    ans += start;
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