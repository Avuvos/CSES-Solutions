//Removal Game - https://cses.fi/problemset/task/1097

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

const int N = 5005;
int n;
vector<ll> stones;
ll dp[N][N][2];
//dp[l][r][k] best score if the board is from l to r, and the kth player moves

ll dfs(int l, int r, int turn) {
    if (l > r) {
        return 0;
    }
    if (dp[l][r][turn] != -1) {
        return dp[l][r][turn];
    }
    if (turn == 0) {
        dp[l][r][turn] = max(stones[l] + dfs(l + 1, r, 1 - turn), stones[r] + dfs(l, r - 1, 1 - turn));
    } else {
        dp[l][r][turn] = min(dfs(l + 1, r, 1 - turn), dfs(l, r - 1, 1 - turn));
    }
    return dp[l][r][turn];
}

void solve() {
    cin >> n;
    stones = vector<ll>(n);
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << dfs(0,n - 1,0) << endl;
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