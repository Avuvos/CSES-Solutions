//Nested Ranges Count - https://cses.fi/problemset/task/2169

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;


typedef tree<int,null_type,less_equal<>,rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i][0] >> ranges[i][1];
        ranges[i][2] = i;
    }

    sort(ranges.begin(), ranges.end(), [&](const array<int, 3>& range1, const array<int, 3>& range2) {
        return range1[0] != range2[0] ? range1[0] < range2[0] : range1[1] > range2[1];
    });

    vector<int> contained(n, 0), contains(n, 0);

    indexed_set st;
    for (auto [l, r, idx]: ranges) {
        contained[idx] = (int) st.size() - st.order_of_key(r);
        st.insert(r);
    }

    st.clear();
    reverse(ranges.begin(), ranges.end());
    for (auto [l, r, idx]: ranges) {
        contains[idx] = st.order_of_key(r + 1);
        st.insert(r);
    }

    for (int i = 0; i < n; i++) {
        cout << contains[i] << " \n"[i == n - 1];
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