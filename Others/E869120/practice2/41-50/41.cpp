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

int dp[200][200];

int main() {
    int d, n, t[200], a[200], b[200], c[200];
    cin >> d >> n;
    rep(i, d) cin >> t[i];
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    for (int i = 0; i < d - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j] <= t[i] && t[i] <= b[j]) {
                for (int k = 0; k < n; ++k) {
                    if (a[k] <= t[i + 1] && t[i + 1] <= b[k]) {
                        chmax(dp[i + 1][k], dp[i][j] + abs(c[j] - c[k]));
                    }
                }
            }
        }
    }
    cout << *max_element(dp[d - 1], dp[d - 1] + n) << endl;

    return 0;
}