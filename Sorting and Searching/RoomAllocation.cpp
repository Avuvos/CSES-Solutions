//Room Allocation - https://cses.fi/problemset/task/1164

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> people(n);
    for (int i = 0; i < n; i++) {
        cin >> people[i][0] >> people[i][1];
        people[i][2] = i;
    }
    sort(people.begin(), people.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> ans(n);
    int room_index = 1;
    
    for (int i = 0; i < n; i++) {
        auto [left, right, index] = people[i];
        if (!pq.empty() && pq.top().first < left) {
            ans[index] = pq.top().second; pq.pop();
            pq.push({right, ans[index]});
        } else {
            ans[index] = room_index;
            pq.push({right, room_index++});
        }
    }

    cout << room_index - 1 << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
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