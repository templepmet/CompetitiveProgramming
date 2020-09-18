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
    int n, dp[1000][3];
    string s[5], c = "RBW";
    cin >> n;
    rep(i, 5) cin >> s[i];
    fill(dp[0], dp[n + 1], INF);
    rep(i, 3) dp[0][i] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            // paint j
            int cnt = 0;
            for (int k = 0; k < 5; ++k) {
                if (s[k][i] != c[j])
                    cnt++;
            }
            for (int k = 0; k < 3; ++k) {
                if (j == k)
                    continue;
                chmin(dp[i + 1][j], dp[i][k] + cnt);
            }
        }
    }
    cout << *min_element(dp[n], dp[n] + 3) << endl;

    return 0;
}