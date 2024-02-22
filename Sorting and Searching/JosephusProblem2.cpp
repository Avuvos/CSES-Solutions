//Josephus Problem II - https://cses.fi/problemset/task/2163

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
typedef long long ll;

using namespace __gnu_pbds;

typedef tree<int,null_type,less<>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    indexed_set st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    int pos = 0;
    for (int i = 0; i < n; i++) {
        int m = (int) st.size();
        pos = (pos + k) % m;
        auto it = st.find_by_order(pos);
        st.erase(it);
        cout << *it << " \n"[i == n - 1];
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