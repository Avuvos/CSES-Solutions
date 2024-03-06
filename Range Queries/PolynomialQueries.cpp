//Polynomial Queries - https://cses.fi/problemset/task/1736/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

struct Update {
    ll a0, d;

    Update() {
        a0 = 0;
        d = 0;
    }

    Update(ll a0, ll set_value) {
        this->a0 = a0;
        this->d = set_value;
    }

    bool operator==(const Update& other) const {
        return d == other.d && a0 == other.a0;
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

    T combine(T l, T r) {
        T ans = (l + r);
        return ans;
    }

    void buildUtil(ll v, ll tl, ll tr, vector<T>&a) {
        if(tl == tr) {
            st[v] = a[tl];
            return;
        }
        ll tm = (tl + tr) >> 1;
        buildUtil(2*v + 1, tl, tm,a);
        buildUtil(2*v + 2,tm+1,tr,a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }

    T apply(T curr, U upd, ll tl, ll tr) {
       ll len = tr - tl + 1;
       T ans = curr + len * (upd.a0 + upd.a0 + (len - 1) * upd.d) / 2; //arithmetic sequence sum
       return ans;
    }

    U combineUpdate(U old_update, U new_update, ll tl, ll tr, ll delta) {
        U ans(old_update.a0 + new_update.a0 + delta, old_update.d + new_update.d);
        return ans;
    }

    void push_down(ll v, ll tl, ll tr) {
        if (lazy[v] == identity_update) return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if (2*v + 2 < 4*n) {
            ll tm = (tl + tr)>>1;
            lazy[2*v + 1] = combineUpdate(lazy[2*v+1], lazy[v], tl, tm, 0);
            lazy[2*v + 2] = combineUpdate(lazy[2*v+2], lazy[v], tm+1,tr, (tm - tl + 1)*lazy[v].d);
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
            lazy[v] = combineUpdate(lazy[v], upd, tl, tr, (tl - l)*upd.d);
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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Lsegtree<ll, Update> st(n, 0, {0, 0});
    st.build(a);

    for (int i = 0; i < q; i++) {
        int op, l, r;
        cin >> op >> l >> r;
        l--, r--;
        if (op == 1) {
            st.update(l, r, {1, 1});
        } else if (op == 2) {
            cout << st.query(l, r) << '\n';
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