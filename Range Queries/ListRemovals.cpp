//List Removals - https://cses.fi/problemset/task/1749/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<int,null_type,less<>,rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    indexed_set st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(i);
    }

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        p--;
        auto it = st.find_by_order(p);
        cout << a[*it] << " \n"[i == n - 1];
        st.erase(it);
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