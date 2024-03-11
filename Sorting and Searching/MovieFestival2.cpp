//Movie Festival II - https://cses.fi/problemset/task/1632

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

const int inf = 1e9 + 17;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    });

    multiset<int> ms;
    for (int i = 0; i < k; i++) {
        ms.insert(-inf);
    }
    int ans = 0;
    for (auto &[start, end]: movies) {
        auto it = ms.lower_bound(start);
        if (it != ms.begin()) {
            it = prev(it);
        }
        if (*it > start) continue;
        ms.erase(ms.find(*it));
        ms.insert(end);
        ans++;
    }
    cout << ans << endl;
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