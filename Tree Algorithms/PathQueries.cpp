//Path Queries - https://cses.fi/problemset/task/1138

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

template<class T, class U>
// T -> node, U -> update.
struct Lsegtree {
    vector<T> st;
    vector<U> lazy;
    int n;
    T identity_element; //combine(id, x) = x for all x
    U identity_update; //apply(id, x) = x for all x

    Lsegtree(int n, T identity_element, U identity_update) {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4*n, identity_element);
        lazy.assign(4*n, identity_update);
    }

    //combine the result of two nodes
    T combine(T l, T r) {
        return l + r;
    }

    void buildUtil(int v, int tl, int tr, vector<T>&a) {
        if (tl == tr) {
            st[v] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        buildUtil(2*v + 1, tl, tm, a);
        buildUtil(2*v + 2, tm + 1, tr, a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }


    //apply the update to curr, which holds the range [tl, tr].
    T apply(T curr, U upd, int tl, int tr) {
        if (upd == identity_update) {
            return curr;
        }
        return upd * (tr - tl + 1);
    }

    //there may be several updates already, so we need to combine them
    U combineUpdate(U old_update, U new_update, int tl, int tr) {
        return old_update + new_update;
    }

    void push_down(int v, int tl, int tr) {
        if (lazy[v] == identity_update) return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if (2*v + 2 < 4*n) {
            int tm = (tl + tr) >> 1;
            lazy[2*v + 1] = combineUpdate(lazy[2*v + 1], lazy[v], tl, tm);
            lazy[2*v + 2] = combineUpdate(lazy[2*v + 2], lazy[v], tm + 1, tr);
        }
        lazy[v] = identity_update;
    }

    T queryUtil(int v, int tl, int tr, int l, int r) {
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
        int tm = (tl + tr) >> 1;
        return combine(queryUtil(2*v + 1, tl, tm, l, r), queryUtil(2*v + 2,tm + 1, tr, l, r));
    }

    void updateUtil(int v, int tl, int tr, int l, int r, U upd) {
        push_down(v, tl, tr);
        if (tr < l || tl > r) return;
        if (tl >= l && tr <= r) {
            lazy[v] = combineUpdate(lazy[v],upd, tl, tr);
            push_down(v, tl, tr);
        }
        else {
            int tm = (tl + tr) >> 1;
            updateUtil(2*v+1, tl,tm, l, r, upd);
            updateUtil(2*v+2,tm+1 ,tr, l, r, upd);
            st[v] = combine(st[2*v + 1], st[2*v + 2]);
        }
    }

    void build(vector<T>& a) {
        assert((int)a.size() == n);
        buildUtil(0, 0, n - 1, a);
    }

    //[l, r]
    T query(int l, int r) {
        return queryUtil(0, 0, n - 1, l, r);
    }

    //[l, r]
    void update(int l,int r, U upd) {
        updateUtil(0, 0, n - 1, l, r, upd);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int timer = 0;
    vector<int> tin(n), tout(n);
    vector<ll> values(2*n);
    auto dfs = [&](auto dfs, int u, int p) -> void {
        tin[u] = timer++;
        values[tin[u]] = a[u];
        for (auto &v: g[u]) {
            if (v == p) continue;
            dfs(dfs, v, u);
        }
        tout[u] = timer++;
        values[tout[u]] = -a[u];
    };
    dfs(dfs, 0, -1);

    Lsegtree<ll, ll> st(2*n, 0, 0);
    st.build(values);

    for (int query = 0; query < q; query++) {
        int op;
        cin >> op;
        if (op == 1) {
            int s, x;
            cin >> s >> x;
            s--;
            st.update(tin[s], tin[s], x);
            st.update(tout[s], tout[s], -x);
        } else if (op == 2) {
            int s;
            cin >> s;
            s--;
            cout << st.query(tin[0], tin[s]) << '\n';
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