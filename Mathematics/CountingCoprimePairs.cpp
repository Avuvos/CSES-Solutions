//Counting Coprime Pairs - https://cses.fi/problemset/task/2417

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

const int N = 1e6 + 17;
int cnt[N];
ll f[N];
ll g[N];

//f[i] is number of pairs with gcd = i
//g[i] is the number of pairs with gcd that is a multiple of i.

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (int i = N - 1; i >= 1; i--) {
        ll multiples = 0;
        for (int j = i; j < N; j += i) {
            multiples += cnt[j];
        }
        g[i] = multiples * (multiples - 1) / 2;
    }

    for (int i = N - 1; i >= 1; i--) {
        f[i] = g[i];
        for (int j = 2 * i; j < N; j += i) {
            f[i] -= f[j];
        }
    }
    cout << f[1] << '\n';
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