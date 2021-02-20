#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[] = { 0, -1, 0, 1, -1, -1, 1, 1 };

int d[2000][2000];
vector<tuple<int, int>> warp[26];

int main() {
    int h, w, sx, sy, gx, gy;
    string f[2000];
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        cin >> f[i];
        for (int j = 0; j < w; ++j) {
            if (f[i][j] == 'S') {
                sy = i;
                sx = j;
            }
            if (f[i][j] == 'G') {
                gy = i;
                gx = j;
            }
            if ('a' <= f[i][j] && f[i][j] <= 'z') {
                warp[f[i][j] - 'a'].emplace_back(j, i);
            }
        }
    }

    fill(d[0], d[h], INF);
    d[sy][sx] = 0;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
    que.emplace(0, sx, sy);
    while (!que.empty()) {
        auto [di, x, y] = que.top();
        que.pop();
        if (d[y][x] < di) {
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h || f[ny][nx] == '#')
                continue;
            if (d[ny][nx] > d[y][x] + 1) {
                d[ny][nx] = d[y][x] + 1;
                que.emplace(d[ny][nx], nx, ny);
            }
        }
        if ('a' <= f[y][x] && f[y][x] <= 'z') {
            for (auto tup : warp[f[y][x] - 'a']) {
                auto [nx, ny] = tup;
                f[ny][nx] = '.';
                if (d[ny][nx] > d[y][x] + 1) {
                    d[ny][nx] = d[y][x] + 1;
                    que.emplace(d[ny][nx], nx, ny);
                }
            }
        }
    }

    cout << (d[gy][gx] == INF ? -1 : d[gy][gx]) << endl;

    return 0;
}