//Grid Paths - https://cses.fi/problemset/task/1625
#pragma GCC optimize("O3","unroll-loops")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0, 0, -1};
unordered_map<char, int> char_to_dir =  {{'R', 0}, {'D', 1}, {'U', 2}, {'L', 3}};

const int n = 7;
const int LEN = 48;
bool seen[n][n];
int index_map[LEN];

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < LEN; i++) {
        index_map[i] = (s[i] == '?' ? -1 : char_to_dir[s[i]]);
    }

    auto dfs = [&](auto dfs, int index, int row, int col) -> int {
        if (index == LEN) {
            return row == n - 1 && col == 0;
        }

        if (row == n - 1 && col == 0) {
            return 0;
        }

        if ((row - 1 < 0 || seen[row - 1][col]) && (row + 1 >= n || seen[row + 1][col])
            && (col - 1 >= 0 && !seen[row][col - 1]) && (col + 1 < n && !seen[row][col + 1])) {
            return 0;
        }

        if ((col - 1 < 0 || seen[row][col - 1]) && (col + 1 >= n || seen[row][col + 1])
            && (row - 1 >= 0 && !seen[row - 1][col]) && (row + 1 < n && !seen[row + 1][col])) {
            return 0;
        }

        int ans = 0;
        seen[row][col] = true;
        if (index_map[index] != -1) {
            int nx = row + dx[index_map[index]];
            int ny = col + dy[index_map[index]];
            if (!(nx < 0 || nx >= n || ny < 0 || ny >= n || seen[nx][ny])) {
                ans += dfs(dfs, index + 1, nx, ny);
            }
        } else {
            for (int dir = 0; dir < 4; dir++) {
                int nx = row + dx[dir];
                int ny = col + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || seen[nx][ny]) {
                    continue;
                }
                ans += dfs(dfs, index + 1, nx, ny);
            }
        }

        seen[row][col] = false;
        return ans;
    };

    cout << dfs(dfs, 0, 0, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}