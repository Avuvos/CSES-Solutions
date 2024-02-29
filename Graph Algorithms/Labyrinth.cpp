//Labyrinth - https://cses.fi/problemset/task/1193

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
    pair<int, int> source, target;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') source = {i, j};
            if (grid[i][j] == 'B') target = {i, j};
        }
    }

    queue<pair<int, int>> q({source});
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<int>> parent(n, vector<int>(m, -1));
    dist[source.first][source.second] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            auto [dx, dy] = DIRECTIONS[dir];
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = 1 + dist[x][y];
                parent[nx][ny] = dir;
                q.push({nx, ny});
            }
        }
    }

    auto [x, y] = target;
    if (dist[x][y] == -1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << dist[x][y] << endl;
    string path;
    while (parent[x][y] != -1) {
        if (parent[x][y] == 0) {
            path.push_back('R');
            y--;
        } else if (parent[x][y] == 1) {
            path.push_back('D');
            x--;
        } else if (parent[x][y] == 2) {
            path.push_back('U');
            x++;
        } else if (parent[x][y] == 3) {
            path.push_back('L');
            y++;
        } else {
            assert(false);
        }
    }
    reverse(path.begin(), path.end());
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