//Movie Festival - https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; ++i) {
        cin >> movies[i].first >> movies[i].second;
    }

    //sort by end time
    sort(movies.begin(), movies.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    });

    //greedily collect events
    int ans = 0, right_end = -1;
    for (auto [start, end]: movies) {
        if (start >= right_end) {
            right_end = end;
            ans++;
        }
    }
    cout << ans << '\n';
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