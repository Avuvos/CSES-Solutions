//Restaurant Customers - https://cses.fi/problemset/task/1619

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> pq; //min priority queue
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        pq.push(a[i].second);
        while (!pq.empty() && pq.top() < a[i].first) {
            pq.pop();
        }
        ans = max(ans, (int)pq.size());
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