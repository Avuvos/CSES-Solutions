//Chessboard and Queens - https://cses.fi/problemset/task/1624

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {-1, 0}, {0, -1},
                                           {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void solve() {
    int n = 8;
    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    auto valid = [&](int row, int col) -> bool {
        if (board[row][col] == '*') {
            return false;
        }
        for (auto [dx, dy]: DIRECTIONS) {
            int nx = row + dx, ny = col + dy;
            while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (board[nx][ny] == 'Q') {
                    return false;
                }
                nx += dx;
                ny += dy;
            }
        }
        return true;
    };

    auto dfs = [&](auto dfs, int queens, int row) -> int {
        if (queens == 0) {
            return 1;
        }
        int ans = 0;
        for (int col = 0; col < n; col++) {
            if (!valid(row, col)) continue;
            board[row][col] = 'Q';
            ans += dfs(dfs, queens - 1, row + 1);
            board[row][col] = '.';
        }
        return ans;
    };

    cout << dfs(dfs, n, 0) << endl;
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