#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD 1000000007
#define EPS 1e-10

using ll = long long;

int h, w, r, c;
char f[100][100];

int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[] = { 0, -1, 0, 1, -1, -1, 1, 1 };

int main() {
    cin >> h >> w >> r >> c;
    r--; c--;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> f[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        int y = r, x = c, cnt = 0;
        while (1) {
            if (y < 0 || y >= h || x < 0 || x >= w || f[y][x] == '#')
                break;
            cnt++;
            y += dy[i];
            x += dx[i];
        }
        ans = max(ans, cnt - 1);
    }
    cout << ans << endl;

    return 0;
}