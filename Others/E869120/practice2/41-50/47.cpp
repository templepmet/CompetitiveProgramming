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

int n;
ll a[2000];
ll dp[2000][2000];

int main() {
    cin >> n;
    rep(i, n) {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    rep(i, n - 1) {
        rep(j, n) {
            if (i % 2) {
                chmax(dp[j][(j + i + 1) % n], dp[j][(j + i) % n] + a[(j + i + 1) % n]);
                chmax(dp[(j + n - 1) % n][(j + i) % n], dp[j][(j + i) % n] + a[(j + n - 1) % n]);
            }
            else {
                if (a[(j + i + 1) % n] > a[(j + n - 1) % n]) {
                    chmax(dp[j][(j + i + 1) % n], dp[j][(j + i) % n]);
                }
                else {
                    chmax(dp[(j + n - 1) % n][(j + i) % n], dp[j][(j + i) % n]);
                }
            }
        }
    }
    ll ans = 0;
    rep(i, n) {
        chmax(ans, *max_element(dp[i], dp[i] + n));
    }
    cout << ans << endl;
    return 0;
}