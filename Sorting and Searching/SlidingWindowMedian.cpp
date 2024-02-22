//Sliding Window Median - https://cses.fi/problemset/task/1076

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
typedef long long ll;

using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<>,rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    indexed_set st;
    for (int i = 0; i < k; i++) {
        st.insert(a[i]);
    }
    int ktag = k & 1 ? k/2 : k/2 - 1;
    cout << *st.find_by_order(ktag) << " ";
    for (int i = k; i < n; i++) {
        st.erase(st.lower_bound(a[i - k] - 1));
        st.insert(a[i]);
        cout << *st.find_by_order(ktag) << " ";
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