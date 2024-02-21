//Elevator Rides - https://cses.fi/problemset/task/1653

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m = (1 << n);
    vector<ll> last(m + 1, INF); //min cost for the last ride on some subset
    vector<ll> rides(m + 1, INF); //min rides for some subset
    rides[0] = 1;
    last[0] = 0;

    for (int mask = 0; mask < m; mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                int prev_mask = mask ^ (1 << i);
                int cost, people;
                if (last[prev_mask] + a[i] <= x) {
                    cost = last[prev_mask] + a[i];
                    people = rides[prev_mask];
                } else {
                    cost = a[i];
                    people = 1 + rides[prev_mask];
                }
                if (people < rides[mask] || (people == rides[mask] && cost < last[mask])) {
                    rides[mask] = people;
                    last[mask] = cost;
                }
            }
        }
    }
    cout << rides[m - 1] << endl;
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