#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 29)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int n, m;
int a[1000], b[1000];
int dp[1000][1001];

int main() {
    while (cin >> n >> m && n > 0) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            a[i] = (b[i] - a[i] + m) % m;
        }
        fill(dp[0], dp[n], INF);
        dp[0][0] = a[0];
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i] < a[i + 1]) {
                    chmin(dp[i + 1][j], dp[i][j] + a[i + 1] - a[i]);
                    if (j > 0)
                        chmin(dp[i + 1][j - 1], dp[i][j]);
                }
                else {
                    chmin(dp[i + 1][j], dp[i][j]);
                    chmin(dp[i + 1][j + 1], dp[i][j] + a[i + 1] - a[i] + m);
                }
            }
        }
        cout << *min_element(dp[n - 1], dp[n - 1] + n + 1) << endl;
    }

    return 0;
}