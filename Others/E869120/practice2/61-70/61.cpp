#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 29)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int d[300][300];

int main() {
    int n, m, a, b, t;
    cin >> n >> m;
    fill(d[0], d[n], INF);
    rep(i, n) d[i][i] = 0;
    rep(i, m) {
        cin >> a >> b >> t;
        a--; b--;
        d[a][b] = t;
        d[b][a] = t;
    }
    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                chmin(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int ans = INF;
    rep(i, n) {
        chmin(ans, *max_element(d[i], d[i] + n));
    }
    cout << ans << endl;

    return 0;
}