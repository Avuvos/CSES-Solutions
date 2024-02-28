//Sliding Window Cost - https://cses.fi/problemset/task/1077

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<>,rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

typedef long long ll;

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
    int median = *st.find_by_order(ktag);
    int prev_median;

    ll big_cost = 0, small_cost = 0;
    multiset<int> big, small;

    auto calc = [&]() -> ll {
        ll left = 1LL * median * small.size() - small_cost;
        ll right = big_cost - 1LL * median * big.size();
        return left + right;
    };

    auto add = [&](int x) -> void {
        if (x >= median) {
            big.insert(x);
            big_cost += x;
        } else {
            small.insert(x);
            small_cost += x;
        }
    };

    auto del = [&](int x) -> void {
        if (big.find(x) != big.end()) {
            big_cost -= x;
            big.erase(big.find(x));
        }
        if (small.find(x) != small.end()) {
            small_cost -= x;
            small.erase(small.find(x));
        }
    };

    auto balance = [&](int start, int bound, multiset<int>& source, multiset<int>& target) -> void {
        vector<int> to_remove;
        auto it = source.lower_bound(start);
        while (it != source.end() && *it < bound) {
            to_remove.push_back(*it);
            target.insert(*it);
            big_cost += (bound == median ? -*it : *it);
            small_cost += (bound == prev_median ? -*it : *it);
            it = next(it);
        }
        for (auto &element: to_remove) {
            source.erase(source.find(element));
        }
    };

    auto rebalance = [&]() -> void {
        if (prev_median < median) {
            balance(prev_median, median, big, small);
        } else {
            balance(median, prev_median, small, big);
        }
    };

    for (int i = 0; i < k; i++) {
        add(a[i]);
    }


    cout << calc() << " ";
    for (int i = k; i < n; i++) {
        //compute new median
        st.erase(st.lower_bound(a[i - k] - 1));
        st.insert(a[i]);
        prev_median = median;
        median = *st.find_by_order(ktag);

        //update and rebalance the sets
        del(a[i - k]);
        add(a[i]);
        rebalance();

        cout << calc() << " \n"[i == n - 1];
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