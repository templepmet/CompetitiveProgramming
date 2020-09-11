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

int h, w;
string f[1000];
int dp[1000][1000];

int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[] = { 0, -1, 0, 1, -1, -1, 1, 1 };

void dfs(int y, int x, int c) {
    dp[y][x] = c;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= h || nx < 0 || nx >= w || f[ny][nx] == '#')
            continue;
        if (dp[ny][nx] > c) {
            dfs(ny, nx, c);
        }
    }
    for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            int ny = y + i;
            int nx = x + j;
            if (ny < 0 || ny >= h || nx < 0 || nx >= w || f[ny][nx] == '#')
                continue;
            if (dp[ny][nx] > c + 1) {
                dfs(ny, nx, c + 1);
            }
        }
        
    }
}

int main() {
    int ch, cw, dh, dw;
    cin >> h >> w;
    cin >> ch >> cw; ch--; cw--;
    cin >> dh >> dw; dh--; dw--;
    for (int i = 0; i < h; ++i) {
        cin >> f[i];
    }
    fill(dp[0], dp[h], INF);
    dfs(ch, cw, 0);
    cout << (dp[dh][dw] == INF ? -1 : dp[dh][dw]) << endl;

    return 0;
}