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

int f[60][60];
int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[] = { 0, -1, 0, 1, -1, -1, 1, 1 };

int main() {
    int h, w;
    while (cin >> w >> h && h > 0) {
        int c, h2 = h * 2, w2 = w * 2;
        fill(f[0], f[h2], INF);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w - 1; ++j) {
                cin >> c;
                if (c == 0) continue;
                f[i * 2][j * 2 + 1] = -1;
                f[i * 2 + 1][j * 2 + 1] = -1;
            }
            if (i == h - 1)
                break;
            for (int j = 0; j < w; ++j) {
                cin >> c;
                f[i * 2 + 1][j * 2 + 1] = -1;
                if (c == 0) continue;
                f[i * 2 + 1][j * 2] = -1;
                f[i * 2 + 1][j * 2 + 1] = -1;
            }
        }
        queue<int> q;
        f[0][0] = 1;
        q.push(0);
        while (!q.empty()) {
            int t = q.front();
            int y = t / w2;
            int x = t % w2;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= h2 - 1 || nx < 0 || nx >= w2 - 1 || f[ny][nx] == -1)
                    continue;
                if (chmin(f[ny][nx], f[y][x] + 1))
                    q.push(ny * w2 + nx);
            }
        }
        cout << (f[h2 - 2][w2 - 2] == INF ? 0 : (f[h2 - 2][w2 - 2] + 1) / 2) << endl;
    }

    return 0;
}