//Counting Towers - https://cses.fi/problemset/task/2413

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

const int N = 1e6 + 17;
ll one[N];
ll two[N];

void pre_calc() {
    one[1] = two[1] = 1;
    for (int i = 2; i < N; i++) {
        one[i] = (4 * one[i - 1] + two[i - 1]) % MOD;
        two[i] = (2 * two[i - 1] + one[i - 1]) % MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    cout << (one[n] + two[n]) % MOD << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pre_calc();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}