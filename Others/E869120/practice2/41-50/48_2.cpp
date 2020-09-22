#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int n, w[300];
int dp[300][300];

bool check(int a, int b) {
    if (a < 0 || b >= n)
        return false;
    if (abs(w[a] - w[b]) > 1)
        return false;
    return true;
}

int main() {
    while (cin >> n && n > 0) {
        fill(dp[0], dp[n], 0);
        rep(i, n) cin >> w[i];
        for (int k = 2; k <= n; ++k) { // k:width
            for (int l = 0; l < n; ++l) {
                int r = l + k - 1;
                if (r >= n)
                    continue;
                if (dp[l + 1][r - 1] == r - l - 1 && check(l, r)) {
                    chmax(dp[l][r], dp[l + 1][r - 1] + 2);
                }
                for (int j = l; j < r; ++j) {
                    chmax(dp[l][r], dp[l][j] + dp[j + 1][r]);
                }
            }
        }
        cout << dp[0][n - 1] << endl;
    }

    return 0;
}