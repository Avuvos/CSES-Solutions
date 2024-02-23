//Two Sets - https://cses.fi/problemset/task/1092/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    ll s = 1LL * n * (n + 1) / 2;
    if (s & 1) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    ll target = s / 2;
    vector<int> a, b;
    for (int i = n; i >= 1; i--) {
        if (target - i >= 0) {
            a.push_back(i);
            target -= i;
        } else {
            b.push_back(i);
        }
    }

    int asz = (int) a.size(), bsz = (int) b.size();

    cout << asz << '\n';
    for (int i = 0; i < asz; i++) {
        cout << a[i] << " \n"[i == asz - 1];
    }
    
    cout << bsz << '\n';
    for (int i = 0; i < bsz; i++) {
        cout << b[i] << " \b"[i == bsz - 1];
    }

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