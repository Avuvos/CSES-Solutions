//Counting Paths - https://cses.fi/problemset/task/1136

#pragma GCC optimize("O3,unroll-loops")
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

    T combine(T l, T r) {
        T ans = (l + r);
        return ans;
    }

    void buildUtil(int v, int tl, int tr, vector<T>&a) {
        if (tl == tr) {
            st[v] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        buildUtil(2*v + 1, tl, tm,a);
        buildUtil(2*v + 2,tm + 1,tr,a);
        st[v] = combine(st[2*v + 1], st[2*v + 2]);
    }

    T apply(T curr, U upd, int tl, int tr) {
        if (upd == identity_update) {
            return curr;
        }
        T ans = curr + (tr - tl + 1) * upd;
        return ans;
    }

    U combineUpdate(U old_update, U new_update, int tl, int tr) {
        U ans = old_update + new_update;
        return ans;
    }

    void push_down(int v, int tl, int tr) {
        if (lazy[v] == identity_update) return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if (2*v + 2 < 4*n) {
            int tm = (tl + tr) >> 1;
            lazy[2*v + 1] = combineUpdate(lazy[2*v + 1], lazy[v], tl,tm);
            lazy[2*v + 2] = combineUpdate(lazy[2*v + 2], lazy[v],tm + 1, tr);
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

    void build(vector<T>a) {
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

const int LOG = 17;
const int N = 2e5 + 3;
int up[LOG][N];
int tin[N];
int tout[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int timer = 0;
    auto dfs = [&](auto dfs, int u, int p) -> void {
        tin[u] = timer++;
        up[0][u] = p;
        for (int i = 1; i < LOG; i++) {
            up[i][u] = up[i - 1][up[i - 1][u]];
        }
        for (auto &v: g[u]) {
            if (v == p) continue;
            dfs(dfs, v, u);
        }
        tout[u] = timer++;
    };
    dfs(dfs, 0, 0);

    auto is_ancestor = [&] (int u, int v) -> bool {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    };

    auto get_lca = [&](int u, int v) -> int {
        if (is_ancestor(u, v)) {
            return u;
        }
        if (is_ancestor(v, u)) {
            return v;
        }
        for (int i = LOG - 1; i >= 0; i--) {
            if (!is_ancestor(up[i][u], v)) {
                u = up[i][u];
            }
        }
        return up[0][u];
    };


    Lsegtree<int, int> st(2*n, 0, 0);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (tin[u] > tin[v]) {
            swap(u, v);
        }
        int lca = get_lca(u, v);
        st.update(tin[lca], tin[u], 1);
        st.update(tin[lca], tin[v], 1);
        st.update(tin[lca], tin[lca], -1);
    }

    for (int i = 0; i < n; i++) {
        cout << st.query(tin[i], tin[i]) - st.query(tout[i], tout[i]) << " \n"[i == n - 1];
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