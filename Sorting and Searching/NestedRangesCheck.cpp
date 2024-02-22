//Nested Ranges Check - https://cses.fi/problemset/task/2168

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> ranges(n); //[left, right, index]
    for (int i = 0; i < n; i++) {
        cin >> ranges[i][0] >> ranges[i][1];
        ranges[i][2] = i;
    }

    vector<int> containing(n, 0), contained(n, 0);

    //sorting by starting time and then by reversed end time.
    sort(ranges.begin(), ranges.end(), [&](array<int, 3> &a, array<int, 3> &b) {
        return (a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]);
    });
    
    int max_right = ranges[0][1];
    for (int i = 1; i < n; i++) {
        auto [left, right, index] = ranges[i];
        if (right <= max_right) {
            contained[index] = 1;
        }
        max_right = max(max_right, right);
    }

    int min_right = ranges[n - 1][1];
    for (int i = n - 2; i >= 0; i--) {
        auto [left, right, index] = ranges[i];
        if (right >= min_right) {
            containing[index] = 1;
        }
        min_right = min(min_right, right);
    }

    for (int i = 0; i < n; i++) {
        cout << containing[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << contained[i] << " \n"[i == n - 1];
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