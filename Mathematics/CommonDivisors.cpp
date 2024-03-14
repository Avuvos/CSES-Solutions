//Common Divisors - https://cses.fi/problemset/task/1081

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

const int N = 1e6 + 17;
int cnt[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x] += 1;
    }
    
    for (int g = N; g >= 1; g--) {
        int multiples = 0;
        for (int x = 1; g * x <= N; x++) {
            multiples += cnt[g * x];
        }
        if (multiples >= 2) {
            cout << g << endl;
            return;
        }
    }

    cout << 1 << endl;
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