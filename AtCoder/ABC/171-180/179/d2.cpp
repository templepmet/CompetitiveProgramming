#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 998244353

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int dp[200000];
int b[200000];
int l[10], r[10];
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> l[i] >> r[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            (b[i] += b[i - 1]) %= MOD;
        }
        (dp[i] += b[i]) %= MOD;
        for (int j = 0; j < k; ++j) {
            if (i + l[j] < n) {
                (b[i + l[j]] += dp[i]) %= MOD;
            }
            if (i + r[j] + 1 < n) {
                (b[i + r[j] + 1] += MOD - dp[i]) %= MOD;
            }
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}