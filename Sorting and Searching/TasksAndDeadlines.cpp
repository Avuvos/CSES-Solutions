//Tasks and Deadlines - https://cses.fi/problemset/task/1630

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> duration(n), deadline(n);

    for (int i = 0; i < n; i++) {
        cin >> duration[i] >> deadline[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](const int i, const int j) {
       return duration[i] < duration[j];
    });

    ll sum_deadlines = 0;
    ll sum_finish_time = 0;
    ll total_time = 0;
    for (auto idx: order) {
        sum_deadlines += deadline[idx];
        sum_finish_time += total_time + duration[idx];
        total_time += duration[idx];
    }

    cout << sum_deadlines - sum_finish_time << endl;
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