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
    int r, c, sy, sx, gy, gx, v[50][50];
    string f[50];
    cin >> r >> c >> sy >> sx >> gy >> gx;
    sy--; sx--; gy--; gx--;
    rep(i, r) cin >> f[i];

    queue<int> q;
    q.push(sy * c + sx);
    fill(v[0], v[r], INF);
    v[sy][sx] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        int y = t / c;
        int x = t % c;
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c || f[ny][nx] == '#')
                continue;
            if (v[ny][nx] > v[y][x] + 1) {
                v[ny][nx] = v[y][x] + 1;
                q.push(ny * c + nx);
            }
        }
    }
    cout << v[gy][gx] << endl;

    return 0;
}