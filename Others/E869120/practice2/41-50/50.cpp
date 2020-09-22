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
ll ad[16][16], tt[16][16];
ll dp[16][1 << 16];
ll cnt[16][1 << 16];

int main() {
    int s, t;
    ll d, ti;
    cin >> n >> m;
    rep(i, m) {
        cin >> s >> t >> d >> ti;
        s--; t--;
        ad[s][t] = d;
        ad[t][s] = d;
        tt[s][t] = ti;
        tt[t][s] = ti;
    }
    fill(dp[0], dp[n], 1e15);
    dp[0][0] = 0;
    cnt[0][0] = 1;
    for (int s = 0; s < (1 << n); ++s) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) { // i to j
                if (ad[i][j] > 0 && (s & 1 << j) == 0 && dp[i][s] + ad[i][j] <= tt[i][j]) {
                    if (dp[j][s | 1 << j] > dp[i][s] + ad[i][j]) {
                        dp[j][s | 1 << j] = dp[i][s] + ad[i][j];
                        cnt[j][s | 1 << j] = cnt[i][s];
                    }
                    else if (dp[j][s | 1 << j] == dp[i][s] + ad[i][j]) {
                        cnt[j][s | 1 << j] += cnt[i][s];
                    }
                }
            }
        }
    }
    if (cnt[0][(1 << n) - 1] == 0)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << dp[0][(1 << n) - 1] << " " << cnt[0][(1 << n) - 1] << endl;

    return 0;
}