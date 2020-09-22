#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 10007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int n;
string s;
int dp[1001][1 << 3];

int c2i(char c) {
    if (c == 'J') return 0;
    if (c == 'O') return 1;
    return 2;
}

int main() {
    cin >> n >> s;
    dp[0][1] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (int k = 0; k < 8; ++k) {
                if ((j & k) > 0 && (k & (1 << c2i(s[i]))) > 0) {
                    (dp[i + 1][k] += dp[i][j]) %= MOD;
                }
            }
        }
    }
    int ans = accumulate(dp[n], dp[n] + 8, 0) % MOD;
    cout << ans << endl;

    return 0;
}