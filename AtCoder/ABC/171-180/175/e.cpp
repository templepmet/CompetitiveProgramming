#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> void chmax(T& a, T b){ if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b){ if (a > b) { a = b; } }

ll dp[3001][3001][4];
ll f[3000][3000];

int main() {
    int r, c, k, x, y;
    ll v;

    cin >> r >> c >> k;
    for (int i = 0; i < k; ++i) {
        cin >> y >> x >> v;
        f[y - 1][x - 1] = v;
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int l = 2; l >= 0; --l) {
                if (l > 0 && dp[i][j][l] == 0)
                    continue;
                chmax(dp[i][j][l + 1], dp[i][j][l] + f[i][j]);
            }
            for (int l = 0; l <= 3; ++l) {
                chmax(dp[i + 1][j][0], dp[i][j][l]);
                chmax(dp[i][j + 1][l], dp[i][j][l]);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= 3; ++i) {
        chmax(ans, dp[r - 1][c - 1][i]);
    }
    cout << ans << endl;

    return 0;
}