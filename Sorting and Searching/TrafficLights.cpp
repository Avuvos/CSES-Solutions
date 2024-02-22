//Traffic Lights - https://cses.fi/problemset/task/1163/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int x, n;
    cin >> x >> n;
    set<int> positions = {0, x};
    set<tuple<int, int, int>> diffs = {make_tuple(x, 0, x)};
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        positions.insert(p);

        auto it = positions.upper_bound(p); //first larger than p
        diffs.insert({*it - p, p, *it});

        it = prev(prev(it)); //first smaller than p
        diffs.insert({p - *it, *it, p});

        while (true) {
            auto [diff, left, right] = *prev(diffs.end());
            if (*positions.upper_bound(left) == right) {
                cout << diff << " ";
                break;
            }
            diffs.erase(*prev(diffs.end()));
        }
    }
    cout << endl;
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