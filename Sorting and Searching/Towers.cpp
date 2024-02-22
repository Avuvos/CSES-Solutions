//Towers - https://cses.fi/problemset/task/1073/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> cubes(n);
    for (int i = 0; i < n; ++i) {
        cin >> cubes[i];
    }
    multiset<int> s;
    for (auto &cube: cubes) {
        auto it = s.upper_bound(cube);
        if (it != s.end()) {
            s.erase(it);
        }
        s.insert(cube);
    }
    cout << s.size() << endl;
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