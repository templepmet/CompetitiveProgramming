#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 10000

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n, k, dp[102][3][2] = {}, a[101] = {}, t;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> t;
        cin >> a[t];
    }
    
    rep(i, 3) dp[1][i][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (a[i] > 0 && a[i] != j + 1) {
                dp[i][j][0] = dp[i][j][1] = 0;
                continue;
            }
            for (int k = 0; k < 3; ++k) {
                if (j == k)
                    (dp[i + 1][k][1] += dp[i][j][0]) %= MOD;
                else
                    (dp[i + 1][k][0] += dp[i][j][0] + dp[i][j][1]) %= MOD;
            }
        }
    }
    int ans = 0;
    rep(i, 3) {
        ans += dp[n][i][0];
        ans += dp[n][i][1];
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}