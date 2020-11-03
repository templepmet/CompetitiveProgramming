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

int dp[1 << 17][17];

int main() {
    int n;
    int x[17], y[17], z[17], d[17][17];

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
    }

    fill(d[0], d[n], INF);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]) + max(0, z[j] - z[i]);
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                chmin(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    fill(dp[0], dp[1 << n], INF);
    dp[0][0] = 0;
    for (int i = 0; i < (1 << n); ++i) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (!(i >> v & 1)) {
                    chmin(dp[i | (1 << v)][v], dp[i][u] + d[u][v]);
                }
            }
        }
    }
    
    cout << dp[(1 << n) - 1][0] << endl;

    return 0;
}