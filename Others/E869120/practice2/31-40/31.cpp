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

int dx[] = { 1, -1, 0, 1, 0, 1 };
int dy[] = { 0, 0, 1, 1, -1, -1 };

int h, w;
int f[102][102];

void dfs(int y, int x) {
    f[y][x] = 2;
    for (int i = 0; i < 6; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i] * (y % 2 ? 1 : -1);
        if (nx < 0 || nx > w + 1 || ny < 0 || ny > h + 1)
            continue;
        if (f[ny][nx] == 0)
            dfs(ny, nx);
    }
}

int main() {
    cin >> w >> h;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin >> f[i][j];
        }
    }
    dfs(0, 0);
    int ans = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (f[i][j] == 1) {
                for (int k = 0; k < 6; ++k) {
                    if (f[i + dy[k]][j + dx[k] * (i % 2 ? 1 : -1)] == 2)
                        ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}