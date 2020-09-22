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

int v, e;
int a[15][15];
int dp[15][1 << 15];

int main() {
    int s, t, d, ans = INF;
    cin >> v >> e;
    fill(a[0], a[v], -1);
    fill(dp[0], dp[v], INF);
    rep(i, e) {
        cin >> s >> t >> d;
        a[s][t] = d;
    }
    dp[0][0] = 0;
    for (int k = 0; k < (1 << v); ++k) {
        for (int i = 0; i < v; ++i) { // dp[i][k] -> dp[j][k | ]
            for (int j = 0; j < v; ++j) {
                if (a[i][j] >= 0 && (k & (1 << j)) == 0) {
                    chmin(dp[j][k | (1 << j)], dp[i][k] + a[i][j]);
                }
            }
        }
    }
    cout << (dp[0][(1 << v) - 1] == INF ? -1 : dp[0][(1 << v) - 1]) << endl;

    return 0;
}