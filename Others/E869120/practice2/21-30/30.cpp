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

int h, w, n, c[10];
string f[1000];
int d[1000][1000];
int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[] = { 0, -1, 0, 1, -1, -1, 1, 1 };

int bfs(int s, int g) {
    int sy = s / w, sx = s % w, gy = g / w, gx = g % w;
    fill(d[0], d[h], INF);
    d[sy][sx] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        int y = t / w;
        int x = t % w;
        rep(i, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w || f[ny][nx] == 'X')
                continue;
            int ret = chmin(d[ny][nx], d[y][x] + 1);
            if (ret)
                q.push(ny * w + nx);
        }
    }
    return d[gy][gx];
}

int main() {
    cin >> h >> w >> n;
    rep(i, h) {
        cin >> f[i];
        rep(j, w) {
            if (f[i][j] == 'S')
                f[i][j] = '0';
            if ('0' <= f[i][j] && f[i][j] <= '9') {
                c[f[i][j] - '0'] = i * w + j;
            }
        }
    }
    int ans = 0;
    rep(i, n) {
        ans += bfs(c[i], c[i + 1]);
    }
    cout << ans << endl;

    return 0;
}