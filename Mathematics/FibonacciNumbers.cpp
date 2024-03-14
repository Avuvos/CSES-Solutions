//Fibonacci Numbers - https://cses.fi/problemset/task/1722

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

vector<vector<ll>> matrix_mult(vector<vector<ll>>& A, vector<vector<ll>>& B) {
    int a_rows = (int) A.size(), a_cols = (int) A[0].size();
    int b_rows = (int) B.size(), b_cols = (int) B[0].size();
    assert(a_cols == b_rows);
    vector<vector<ll>> C(a_rows, vector<ll>(b_cols, 0));
    for (int i = 0; i < a_rows; i++) {
        for (int j = 0; j < b_cols; j++) {
            for (int k = 0; k < a_cols; k++) {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> matrix_expo(vector<vector<ll>>& A, ll b) {
    vector<vector<ll>> res(A.size(), vector<ll>(A.size(), 0));
    for (int i = 0; i < (int) res.size(); i++) {
        res[i][i] = 1;
    }
    while (b > 0) {
        if (b & 1) {
            res = matrix_mult(res, A);
        }
        A = matrix_mult(A, A);
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> f = {{0, 1}, {1, 1}};
    cout << matrix_expo(f, n)[0][1] << endl;
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