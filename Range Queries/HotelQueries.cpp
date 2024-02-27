//Hotel Queries - https://cses.fi/problemset/task/1143

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;


struct Node {
    ll val;
    ll max_on_prefix;

    Node() {
        val = 0;
        max_on_prefix = 0;
    }

    Node(ll val, ll max_on_prefix) {
        this->val = val;
        this->max_on_prefix = max_on_prefix;
    }

    bool operator==(const Node &other) {
        return val == other.val && max_on_prefix == other.max_on_prefix;
    }

};



template<class T, class U>
// T -> node, U -> update.
struct Lsegtree {
    vector<T> st;
    vector<U> lazy;
    ll n;
    T identity_element; //combine(id, x) = x for all x
    U identity_update; //apply(id, x) = x for all x

    Lsegtree(ll n, T identity_element, U identity_update) {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4*n, identity_element);
        lazy.assign(4*n, identity_update);
    }

    //change this function as required.
    //right now this is sum of two nodes.
    //we can change it to max(l, r), gcd(l, r), etc..
    T combine(T l, T r) {
        T ans;
        ans.val = max(l.val, r.val);
        ans.max_on_prefix = max({ans.val, l.max_on_prefix, r.max_on_prefix});
        return ans;
    }

    void buildUtil(ll v, ll tl, ll tr, vector<T>&a) {
        if(tl == tr) {
            st[v] = a[tl];
            return;
        }
        ll tm = (tl + tr)>>1;
        buildUtil(2*v + 1, tl, tm,a);
        buildUtil(2*v + 2,tm+1,tr,a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }

    //change the following 2 functions, and you're more or less done.
    //apply the update to curr, which holds the range from tl to tr.
    //this is modification for all elements in the range
    //if we wanted to add, we could change it to curr + (tr-tl+1)*upd.
    T apply(T curr, U upd, ll tl, ll tr) {
        T ans;
        ans.val = curr.val + upd;
        ans.max_on_prefix = ans.val;
        return ans;
    }

    //there may be several updates already, so we need to combine them
    //this is modification, so we just replace the old value with new value
    //if we wanted addition, we could do ans = old_update + new_update
    U combineUpdate(U old_update, U new_update, ll tl, ll tr) {
        U ans = old_update + new_update;
        return ans;
    }

    void push_down(ll v, ll tl, ll tr) {
        if (lazy[v] == identity_update) return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if (2*v + 2 < 4*n) {
            ll tm = (tl + tr)>>1;
            lazy[2*v + 1] = combineUpdate(lazy[2*v+1], lazy[v], tl, tm);
            lazy[2*v + 2] = combineUpdate(lazy[2*v+2], lazy[v], tm+1,tr);
        }
        lazy[v] = identity_update;
    }

    T queryUtil(ll v, ll tl, ll tr, ll l, ll r) {
        push_down(v, tl, tr);
        if (l > r) {
            return identity_element;
        }
        if (tr < l || tl > r) {
            return identity_element;
        }
        if (l <= tl && r >= tr) {
            return st[v];
        }
        ll tm = (tl + tr)>>1;
        return combine(queryUtil(2*v + 1, tl, tm, l, r), queryUtil(2*v + 2,tm+1, tr, l, r));
    }

    void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd) {
        push_down(v, tl, tr);
        if (tr < l || tl > r) return;
        if (tl >= l && tr <= r) {
            lazy[v] = combineUpdate(lazy[v],upd, tl, tr);
            push_down(v, tl, tr);
        }
        else {
            ll tm = (tl + tr) >> 1;
            updateUtil(2*v+1, tl,tm, l, r, upd);
            updateUtil(2*v+2,tm+1 ,tr, l, r, upd);
            st[v] = combine(st[2*v + 1], st[2*v + 2]);
        }
    }

    void build(vector<T>a) {
        assert((int)a.size() == n);
        buildUtil(0, 0, n - 1, a);
    }

    //[l, r]
    T query(ll l, ll r) {
        return queryUtil(0, 0, n - 1, l, r);
    }

    //[l, r]
    void update(ll l,ll r, U upd) {
        updateUtil(0, 0, n - 1, l, r, upd);
    }
};



void solve() {
    int n, q;
    cin >> n >> q;
    vector<Node> a(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = Node(x, x);
    }
    Node id_node;
    Lsegtree<Node, ll> st(n, id_node, 0);
    st.build(a);

    auto find_first_hotel = [&](ll x) -> ll {
        ll left = 0, right = n - 1, index = -1;
        while (left <= right) {
            ll mid = left + (right - left)/2;
            if (st.query(0, mid).max_on_prefix >= x) {
                index = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return index;
    };

    for (int i = 0; i < q; i++) {
        ll x;
        cin >> x;
        ll hotel_index = find_first_hotel(x);
        if (hotel_index == -1) {
            cout << 0 << " ";
            continue;
        }
        cout << hotel_index + 1 << " ";
        st.update(hotel_index, hotel_index, -x);
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