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
    int d[10][10];
    int h, w, a, ans = 0;
    cin >> h >> w;
    rep(i, 10)rep(j, 10)cin >> d[i][j];
    rep(k, 10)rep(i, 10)rep(j, 10) chmin(d[i][j], d[i][k] + d[k][j]);
    rep(i, h) {
        rep(j, w) {
            cin >> a;
            if (a >= 0)
                ans += d[a][1];
        }
    }
    cout << ans << endl;

    return 0;
}