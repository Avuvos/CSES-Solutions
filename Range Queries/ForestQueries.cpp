//Forest Queries - https://cses.fi/problemset/task/1652/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            a[i][j] = (c == '*');
        }
    }

    vector<vector<int>> ps;
    ps = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    for (int row = 1; row < n + 1; ++row) {
        for (int col = 1; col < n + 1; ++col) {
            ps[row][col] = a[row - 1][col - 1] + ps[row - 1][col] + ps[row][col - 1] - ps[row - 1][col - 1];
        }
    }

    auto sumRegion = [&](int top_row, int left_col, int bot_row, int right_col) {
        return ps[bot_row + 1][right_col + 1] - ps[bot_row + 1][left_col] - ps[top_row][right_col + 1] + ps[top_row][left_col];
    };

    for (int i = 0; i < q; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--, x1--, y2--, x2--;
        cout << sumRegion(y1, x1, y2, x2) << '\n';
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