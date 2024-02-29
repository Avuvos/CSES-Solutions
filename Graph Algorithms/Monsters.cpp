//Monsters - https://cses.fi/problemset/task/1194

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    auto valid = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
    };

    auto is_border = [&](int x, int y) {
        return x == 0 || y == 0 || x == n - 1 || y == m - 1;
    };

    vector<vector<int>> burn(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                q.push({i, j});
                burn[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                sx = i;
                sy = j;
            }
        }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy]: DIRECTIONS) {
            int nx = x + dx;
            int ny = y + dy;
            if (valid(nx, ny) && burn[nx][ny] == -1) {
                burn[nx][ny] = burn[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    q.push({sx, sy});
    vector<vector<int>> parent(n, vector<int>(m, -1));
    int ans_x = -1, ans_y = -1;
    bool found = false;
    int time = 1;
    while (!q.empty()) {
        int sz = (int) q.size();
        for (int i = 0; i < sz; i++) {
            auto [x, y] = q.front(); q.pop();
            if (valid(x, y) && is_border(x, y)) {
                ans_x = x, ans_y = y;
                found = true;
                break;
            }
            for (int dir = 0; dir < 4; dir++) {
                auto [dx, dy] = DIRECTIONS[dir];
                int nx = x + dx;
                int ny = y + dy;
                if (valid(nx, ny) && (burn[nx][ny] == -1 || burn[nx][ny] > time) && parent[nx][ny] == -1) {
                    q.push({nx, ny});
                    parent[nx][ny] = dir;
                }
            }
        }
        time++;
        if (found) break;
    }
    
    if (!found) {
        cout << "NO" << endl;
        return;
    }

    string path;
    while (!(ans_x == sx && ans_y == sy)) {
        if (parent[ans_x][ans_y] == 0) {
            path.push_back('R');
            ans_y--;
        } else if (parent[ans_x][ans_y] == 1) {
            path.push_back('D');
            ans_x--;
        } else if (parent[ans_x][ans_y] == 2) {
            path.push_back('U');
            ans_x++;
        } else if (parent[ans_x][ans_y] == 3) {
            path.push_back('L');
            ans_y++;
        } else {
            assert(false);
        }
    }
    reverse(path.begin(), path.end());
    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;
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