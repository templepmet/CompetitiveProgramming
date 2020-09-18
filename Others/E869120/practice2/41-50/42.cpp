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

int dp[1001];

int main() {
    int n, m, d[1000], c[1000], ans = INF;
    cin >> n >> m;
    rep(i, n) cin >> d[i];
    rep(i, m) cin >> c[i];
    fill(dp, dp + n + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            chmin(dp[j + 1], dp[j] + d[j] * c[i]);
        }
        chmin(ans, dp[n]);
    }
    cout << ans << endl;

    return 0;
}