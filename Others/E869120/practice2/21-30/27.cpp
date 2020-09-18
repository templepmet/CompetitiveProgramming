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

int m, n, f[90][90], v[90][90];
int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int ans = 0;

void dfs(int y, int x, int d) {
    v[y][x] = 1;
    chmax(ans, d);
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || f[ny][nx] == 0 || v[ny][nx])
            continue;
        dfs(ny, nx, d + 1);
    }
    v[y][x] = 0;
}

int main() {
    cin >> m >> n;
    rep(i, n)rep(j,m) cin >> f[i][j];

    rep(i, n) {
        rep(j, m) {
            if (f[i][j]) {
                dfs(i, j, 1);
            }
        }
    }

    cout << ans << endl;

    return 0;
}