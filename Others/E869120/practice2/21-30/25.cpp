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

int w, h;
int f[50][50];
int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[] = { 0, -1, 0, 1, -1, -1, 1, 1 };

void dfs(int y, int x) {
    f[y][x] = 0;
    for (int i = 0; i < 8; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= h || nx < 0 || nx >= w || f[ny][nx] == 0)
            continue;
        dfs(ny, nx);
    }
}

int main() {
    while (cin >> w >> h && w > 0) {
        int ans = 0;
        rep(i, h)rep(j, w)cin >> f[i][j];
        rep(i, h) {
            rep(j, w) {
                if (f[i][j]) {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}