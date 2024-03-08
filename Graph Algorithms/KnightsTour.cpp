//Knight's Tour - https://cses.fi/problemset/task/1689

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

const vector<pair<int, int>> DIRECTIONS = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                           {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

void solve() {
    int start_col, start_row;
    cin >> start_col >> start_row;
    start_col--, start_row--;

    int n = 8;
    vector<vector<int>> ans(n, vector<int>(n, -1));

    auto valid = [&](int x, int y) -> bool {
        return x >= 0 && x < n && y >= 0 && y < n && ans[x][y] == -1;
    };

    auto get_move_score = [&](int x, int y) -> int {
        int score = 0;
        for (auto [dx, dy]: DIRECTIONS) {
            int nx = x + dx;
            int ny = y + dy;
            score += valid(nx, ny);
        }
        return score;
    };

    auto generate_possible_moves = [&](int x, int y) -> vector<array<int, 3>> {
        vector<array<int, 3>> res;
        for (auto [dx, dy]: DIRECTIONS) {
            int nx = x + dx;
            int ny = y + dy;
            if (valid(nx, ny)) {
                res.push_back({get_move_score(nx, ny), nx, ny});
            }
        }
        sort(res.begin(), res.end());
        return res;
    };

    auto dfs = [&](auto dfs, int x, int y, int current) -> bool {
        ans[x][y] = current;
        if (current == n * n) {
            return true;
        }
        auto moves = generate_possible_moves(x, y);
        for (auto [cnt, nx, ny]: moves) {
            if (dfs(dfs, nx, ny, current + 1)) {
                return true;
            }
        }
        ans[x][y] = -1;
        return false;
    };

    dfs(dfs, start_row, start_col, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " \n"[j == n - 1];
        }
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