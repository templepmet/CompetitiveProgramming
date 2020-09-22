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

int n, r[100], c[100];
int dp[100][100];

int calc(int a, int b) {
    if (dp[a][b] < INF)
        return dp[a][b];
    if (a == b)
        return dp[a][b] = 0;
    int v = INF;
    for (int i = a; i < b; ++i) {
        chmin(v, calc(a, i) + calc(i + 1, b) + r[a] * r[i + 1] * c[b]);
    }
    return dp[a][b] = v;
}

int main() {
    cin >> n;
    rep(i, n) cin >> r[i] >> c[i];
    fill(dp[0], dp[100], INF);
    cout << calc(0, n - 1) << endl;

    return 0;
}