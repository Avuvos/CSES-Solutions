//Palindrome Reorder - https://cses.fi/problemset/task/1755

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (auto &c: s) cnt[c - 'A']++;
    string left, mid, right;
    for (int i = 0; i < 26; i++) {
        char c = (char) (i + 'A');
        if (cnt[i] & 1) {
            if (mid != "") {
                cout << "NO SOLUTION" << endl;
                return;
            }
            mid = c;
        }
        left += string(cnt[i] / 2, c);
        right += string(cnt[i] / 2, c);
    };
    reverse(right.begin(), right.end());
    cout << left + mid + right << endl;
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