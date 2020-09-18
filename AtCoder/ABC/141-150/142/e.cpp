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

int dp[1001][1 << 12];

int main() {
    int n, m, a[1000], b, c[1000] = {}, t;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b;
        while (b--) {
            cin >> t;
            c[i] += (1 << (t - 1));
        }
    }
    fill(dp[0], dp[m + 1], INF);
    dp[0][0] = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            if (dp[i][j] == INF)
                continue;
            chmin(dp[i + 1][j], dp[i][j]);
            chmin(dp[i + 1][j | c[i]], dp[i][j] + a[i]);
        }
    }
    cout << (dp[m][(1 << n) - 1] == INF ? -1 : dp[m][(1 << n) - 1]) << endl;

    return 0;
}