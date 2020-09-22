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
int a[15][15];
int dp[15][1 << 15];

int rec(int v, int b) {
    if (dp[v][b] >= 0)
        return dp[v][b];
    if (b == ((1 << n) - 1) && v == 0)
        return dp[v][b] = 0;
    int t = INF;
    for (int i = 0; i < n; ++i) {
        if (a[v][i] >= 0 && ((b & (1 << i)) == 0))
            chmin(t, rec(i, b | (1 << i)) + a[v][i]);
    }
    return dp[v][b] = t;
}

int main() {
    int s, t, d;
    cin >> n >> m;
    fill(a[0], a[n], -1);
    fill(dp[0], dp[n], -1);
    rep(i, m) {
        cin >> s >> t >> d;
        a[s][t] = d;
    }
    int ans = rec(0, 0);
    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}