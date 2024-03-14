//Throwing Dice - https://cses.fi/problemset/task/1096

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

vector<vector<ll>> matrix_mult(vector<vector<ll>>& A, vector<vector<ll>>& B, ll mod) {
    int a_rows = (int) A.size(), a_cols = (int) A[0].size();
    int b_rows = (int) B.size(), b_cols = (int) B.size();
    assert(a_cols == b_rows);
    vector<vector<ll>> C(a_rows, vector<ll>(b_rows, 0));
    for (int i = 0; i < a_rows; i++) {
        for (int j = 0; j < b_cols; j++) {
            for (int k = 0; k < a_cols; k++) {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= mod;
            }
        }
    }
    return C;
}

vector<vector<ll>> matrix_expo(vector<vector<ll>>& A, ll b, ll m) {
    vector<vector<ll>> res(A.size(), vector<ll>(A[0].size(), 1));
    while (b > 0) {
        if (b & 1) {
            res = matrix_mult(res, A, m);
        }
        A = matrix_mult(A, A, m);
        b >>= 1;
    }
    return res;
}


void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> f = {{0, 1, 0, 0, 0, 0},
                            {0, 0, 1, 0 ,0, 0},
                            {0, 0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 1, 0},
                            {0, 0, 0, 0, 0, 1},
                            {1, 1, 1, 1, 1, 1}};
    auto fn = matrix_expo(f, n, MOD);
    cout << fn[0][0] << endl;
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