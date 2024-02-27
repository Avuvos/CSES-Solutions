//Dynamic Range Sum Queries - https://cses.fi/problemset/task/1648

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

const int N = 3e5;  // limit for array size
int n;  // array size
ll sums[2 * N];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) {
        sums[i] = sums[i << 1] + sums[i << 1 | 1];
    }
}

void modify(int p, int value) {  // set value at position p
    for (sums[p += n] = value; p > 1; p >>= 1) {
        sums[p >> 1] = sums[p] + sums[p ^ 1];
    }
}

ll query(int l, int r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            res += sums[l];
            l++;
        }
        if (r & 1) {
            r--;
            res += sums[r];
        }
    }
    return res;
}

void solve() {
    int q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sums[i + n] = a[i];
    }

    build();

    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            ll k, u;
            cin >> k >> u;
            k--;
            modify(k, u);
        } else if (op == 2) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << query(l, r + 1) << '\n';
        } else {
            assert(false);
        }
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