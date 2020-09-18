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

int dp[20001][256];

int main() {
    int n, m, c[16], x[20000];
    while (cin >> n >> m && n > 0) {
        rep(i, m) cin >> c[i];
        rep(i, n) cin >> x[i];
        fill(dp[0], dp[n + 1], INF);
        dp[0][128] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < 256; ++k) {
                    int nx = max(0, min(k + c[j], 255));
                    chmin(dp[i + 1][nx], dp[i][k] + (int)pow(nx - x[i], 2));
                }
            }
        }
        cout << *min_element(dp[n], dp[n] + 256) << endl;
    }

    return 0;
}