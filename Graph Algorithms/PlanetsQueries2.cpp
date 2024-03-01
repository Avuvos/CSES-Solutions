//Planets Queries II - https://cses.fi/problemset/task/1160

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

struct functional_graph {
    int n = 0;
    vector<int> F;
    vector<bool> in_cycle;
    vector<int> which_cycle;
    vector<int> cycle_root;
    vector<int> cycle_position;
    vector<int> depth;
    vector<vector<int>> children;
    vector<vector<int>> cycles;
    vector<int> jump, jump_dist;

    functional_graph(const vector<int> &f = {}) {
        if (!f.empty())
            build(f);
    }

    void build(const vector<int> &f) {
        F = f;
        n = int(F.size());
        in_cycle.assign(n, false);
        which_cycle.assign(n, -1);
        cycle_root.assign(n, -1);
        cycle_position.assign(n, -1);
        depth.assign(n, -1);
        children.assign(n, {});
        cycles.clear();

        vector<int> seen(n, -1);

        for (int i = 0; i < n; i++) {
            if (seen[i] >= 0) continue;

            int x = i;
            do {
                seen[x] = i;
                x = F[x];
            } while (seen[x] < 0);

            if (seen[x] != i)
                continue;

            vector<int> cycle;
            int y = x;
            do {
                in_cycle[y] = true;
                cycle_position[y] = int(cycle.size());
                which_cycle[y] = int(cycles.size());
                cycle.push_back(y);
                y = F[y];
            } while (y != x);
            cycles.push_back(cycle);
        }

        seen.assign(n, 0);

        for (int i = 0; i < n; i++) {
            seen[F[i]] += !in_cycle[i];
        }

        for (int i = 0; i < n; i++) {
            children[i].reserve(seen[i]);
        }

        seen.clear();

        for (int i = 0; i < n; i++) {
            if (!in_cycle[i]) {
                children[F[i]].push_back(i);
            }
        }

        jump.assign(n, -1);
        jump_dist.assign(n, -1);
        int cyc_root = -1, which_cyc = -1;

        auto dfs = [&](auto self, int node, int parent) -> void {
            depth[node] = parent < 0 ? 0 : depth[parent] + 1;
            cycle_root[node] = cyc_root;
            which_cycle[node] = which_cyc;
            jump[node] = parent < 0 ? node : jump_dist[parent] == jump_dist[jump[parent]] ? jump[jump[parent]] : parent;
            jump_dist[node] = depth[node] - depth[jump[node]];

            for (int child : children[node]) {
                self(self, child, node);
            }
        };

        for (int i = 0; i < n; i++) {
            if (!in_cycle[i]) continue;
            cyc_root = i;
            which_cyc = which_cycle[i];
            dfs(dfs, i, -1);
        }
    }

    int cycle_length(int node) {
        return int(cycles[which_cycle[node]].size());
    }

    int go_forward(int v, ll k) {
        if (k >= depth[v]) {
            int root = cycle_root[v];
            k -= depth[v];
            int cyc = which_cycle[root];
            ll position = (cycle_position[root] + k) % cycles[cyc].size();
            return cycles[cyc][position];
        }

        while (k > 0) {
            if (jump_dist[v] <= k) {
                k -= jump_dist[v];
                v = jump[v];
            } else {
                k--;
                v = F[v];
            }
        }

        return v;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> nxt(n);
    for (int i = 0; i < n; i++) {
        cin >> nxt[i];
        nxt[i]--;
    }
    functional_graph fn(nxt);

    for (int i = 0; i < q; i++) {
        int source, target;
        cin >> source >> target;
        source--, target--;
        //same node
        if (source == target) {
            cout << 0 << '\n';
            continue;
        }
        //cannot reach the same cycle
        if ((fn.which_cycle[source] != fn.which_cycle[target])) {
            cout << -1 << '\n';
            continue;
        }
        //source on cycle and target is not
        if (fn.cycle_position[source] != -1 && fn.cycle_position[target] == -1) {
            cout << -1 << '\n';
            continue;
        }
        //target is "deeper" than source, so can never reach him
        if (fn.depth[source] < fn.depth[target]) {
            cout << -1 << '\n';
            continue;
        }
        //target is not on a cycle, so we can get to it only if we are on the same chain
        if (fn.depth[target] > 0) {
            int dist = fn.depth[source] - fn.depth[target];
            cout << (fn.go_forward(source, dist) == target ? dist : -1) << '\n';
            continue;
        }
        //start by moving the source to the cycle then calc the diff between indices.
        int ans = fn.depth[source];
        source = fn.go_forward(source, fn.depth[source]);
        ans += fn.cycle_position[target];
        ans -= fn.cycle_position[source];
        if (fn.cycle_position[source] > fn.cycle_position[target]) {
            ans += fn.cycle_length(source);
        }
        cout << ans << '\n';
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