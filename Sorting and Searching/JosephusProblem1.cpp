//Josephus Problem I - https://cses.fi/problemset/task/2162

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    queue<int> queue;
    for (int i = 1; i <= n; i++) {
        queue.push(i);
    }
    while (!queue.empty()) {
        int current = queue.front(); queue.pop();
        queue.push(current);
        int next = queue.front(); queue.pop();
        cout << next << " ";
    }
    cout << endl;
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