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

int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[] = { 0, -1, 0, 1, -1, -1, 1, 1 };

int main() {
    int h, w, d[50][50];
    string f[50];
    cin >> h >> w;
    rep(i, h) cin >> f[i];
    
    queue<int> q;
    q.push(0);
    fill(d[0], d[h], INF);
    d[0][0] = 0;
    while (!q.empty()) {
        int t = q.front();
        int y = t / w;
        int x = t % w;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w || f[ny][nx] == '#')
                continue;
            if (chmin(d[ny][nx], d[y][x] + 1))
                q.push(ny * w + nx);
        }
    }

    int y = h - 1, x = w - 1;
    if (d[y][x] == INF) {
        cout << -1 << endl;
        return 0;
    }
    while (1) {
        f[y][x] = '#';
        if (y == 0 && x == 0)
            break;
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w || f[ny][nx] == '#')
                continue;
            if (d[y][x] == d[ny][nx] + 1) {
                y = ny;
                x = nx;
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += count(f[i].begin(), f[i].end(), '.');
    }
    cout << ans << endl;

    return 0;
}