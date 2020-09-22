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

int n, m;
int a[100000];
int b[20][100001];
int c[20];
int dp[1 << 20];

int main() {
    cin >> n >> m;
    rep(i, n) {
        cin >> a[i];
        a[i]--;
        b[a[i]][i + 1] = 1;
        c[a[i]]++;
    }
    rep(i, m) {
        rep(j, n) {
            b[i][j + 1] += b[i][j];
        }
    }
    fill(dp, dp + (1 << m), INF);
    dp[0] = 0;
    for (int s = 0; s < (1 << m); ++s) {
        int l = 0;
        for (int i = 0; i < m; ++i) {
            if (s & (1 << i)) {
                l += c[i];
            }
        }
        for (int i = 0; i < m; ++i) {
            if ((s & (1 << i)) == 0) {
                chmin(dp[s | (1 << i)], dp[s] + (c[i] - (b[i][l + c[i]] - b[i][l])));
            }
        }
    }
    cout << dp[(1 << m) - 1] << endl;

    return 0;
}