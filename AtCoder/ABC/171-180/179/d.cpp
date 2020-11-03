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

int main() {
    int n, k, l, r;
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 0; i < k; ++i) {
        cin >> l >> r;
        fill(b, b + n, 0);
        for (int j = 0; j < n; ++j) {
            if (j > 0) {
                (b[j] += b[j - 1]) %= MOD;
            }
            (dp[j] += b[j]) %= MOD;
            if (j + l < n) {
                (b[j + l] += dp[j]) %= MOD;
            }
            if (j + r + 1 < n) {
                (b[j + r + 1] -= dp[j]) %= MOD;
            }
        }
        for (int j = 0; j < n; ++j) {
            cout << dp[j] << " ";
        }
        cout << endl;
        
        for (int j = 0; j < n; ++j) {
            cout << b[j] << " ";
        }
        cout << endl;
    }
    cout << dp[n - 1] << endl;

    return 0;
}