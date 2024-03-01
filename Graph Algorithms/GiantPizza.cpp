//Giant Pizza - https://cses.fi/problemset/task/1684

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(2*m);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        char op1, op2;
        int top1, top2;
        cin >> op1 >> top1 >> op2 >> top2;
        top1--, top2--;
        if (op1 == '+') top1 += m;
        if (op2 == '+') top2 += m;
        int not_top1 = (top1 >= m ? top1 - m : top1 + m);
        int not_top2 = (top2 >= m ? top2 - m : top2 + m);
        g[not_top1].push_back(top2);
        g[not_top2].push_back(top1);
        edges.emplace_back(not_top1, top2);
        edges.emplace_back(not_top2, top1);
    }

    vector<vector<int>> scc_members(2*m);
    vector<int> d(2*m, -1), low(2*m, 0), scc(2*m, -1);
    vector<bool> stacked(2*m, false);
    stack<int> s;
    int ticks = 0, current_scc = 0;
    auto tarjan = [&](auto tarjan, int u) -> void {
        d[u] = low[u] = ticks++;
        s.push(u);
        stacked[u] = true;
        for (int& v : g[u]){
            if (d[v] == -1){
                tarjan(tarjan, v);
                low[u] = min(low[u], low[v]);
            }else if (stacked[v]){
                low[u] = min(low[u], low[v]);
            }
        }
        if (d[u] == low[u]){
            int v;
            do {
                v = s.top();
                s.pop();
                stacked[v] = false;
                scc[v] = current_scc;
                scc_members[current_scc].push_back(v);
            } while (u != v);
            current_scc++;
        }
    };

    for (int i = 0; i < 2*m; i++) {
        if (d[i] == -1) {
            tarjan(tarjan, i);
        }
    }

    for (int i = 0; i < m; i++) {
        if (scc[i] == scc[i + m]) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    //build the condensation graph
    vector<set<int>> scc_graph(current_scc);
    for (auto [u, v]: edges) {
        if (scc[u] != scc[v]) {
            scc_graph[scc[u]].insert(scc[v]);
        }
    }

    // Note: if there is a cycle, the size of the return will be less than n.
    // topsort template of neal wu
    auto topological_sort = [&] (const vector<set<int>> &adj) -> vector<int> {
        int n = (int) adj.size();
        vector<int> in_degree(n, 0);
        vector<int> order;

        for (int i = 0; i < n; i++) {
            for (int neighbor : adj[i]) {
                in_degree[neighbor]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) {
                order.push_back(i);
            }
        }

        int current = 0;
        while (current < (int) order.size()) {
            int node = order[current++];
            for (int neighbor : adj[node]) {
                if (--in_degree[neighbor] == 0) {
                    order.push_back(neighbor);
                }
            }
        }
        return order;
    };

    vector<int> order = topological_sort(scc_graph);
    reverse(order.begin(), order.end());

    vector<int> color(m, -1); //1 = true, 0 = false
    for (int comp = 0; comp < current_scc; comp++) {
        for (auto node: scc_members[order[comp]]) {
            int current_topping = node >= m ? node - m : node;
            if (color[current_topping] != -1) continue;
            color[current_topping] = node >= m ? 1 : 0;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << (color[i] ? '+' : '-') << " \n"[i == m - 1];
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