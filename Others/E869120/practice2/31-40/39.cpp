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

int main() {
    int n, a;
    unsigned long long dp[100][21] = {};
    cin >> n >> a;
    dp[0][a] = 1;
    rep(i, n - 2) {
        cin >> a;
        for (int j = 0; j <= 20; ++j) {
            if (j - a >= 0) {
                dp[i + 1][j - a] += dp[i][j];
            }
            if (j + a <= 20) {
                dp[i + 1][j + a] += dp[i][j];
            }
        }
    }
    cin >> a;
    cout << dp[n - 2][a] << endl;

    return 0;
}