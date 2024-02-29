//Road Construction - https://cses.fi/problemset/task/1676

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

struct dsu {
    vector<int> parent;
    vector<int> size_;

    dsu(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size_.resize(n, 1);
    }

    int find_(int x) {
        return x == parent[x] ? x : parent[x] = find_(parent[x]);
    }
    bool union_(int x,int y) {
        int X = find_(x), Y = find_(y);
        if (X == Y) {
            return false;
        }
        if (size_[X] < size_[Y]) {
            swap(X, Y);
        }
        parent[Y] = X;
        size_[X] += size_[Y];
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    dsu ds(n);
    int mx = 1;
    int comps = n;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (ds.union_(u, v)) {
            comps--;
        }
        mx = max(mx, ds.size_[ds.find_(u)]);
        cout << comps << " " << mx << '\n';
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