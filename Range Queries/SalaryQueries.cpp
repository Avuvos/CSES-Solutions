//Salary Queries - https://cses.fi/problemset/task/1144

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

typedef tree<int,null_type,less_equal<>,rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    indexed_set st;
    map<int, int> mp; //emp -> salary

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        mp[i] = p[i];
        st.insert(p[i]);
    }

    for (int i = 0; i < q; i++) {
        char op;
        cin >> op;
        if (op == '!') {
            int k, x;
            cin >> k >> x;
            k--;
            int prev_salary = mp[k];
            st.erase(st.lower_bound(prev_salary - 1));
            st.insert(x);
            mp[k] = x;
        } else if (op == '?') {
            int a, b;
            cin >> a >> b;
            cout << st.order_of_key(b + 1) - st.order_of_key(a) << '\n';
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