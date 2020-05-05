#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define INF (1 << 29)
#define INFL (1LL << 61)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[] = { 0, -1, 0, 1, -1, -1, 1, 1 };

int h, w;
char s[20][20];
int f[400][400];

void print() {
    for (int i = 0; i < h * w; ++i) {
        for (int j = 0; j < h * w; ++j) {
            if (f[i][j] == INF) {
                printf("-");
            }
            else {
                printf("%d", f[i][j]);
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    cin >> h >> w;
    char c;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> s[i][j];
        }
    }

    fill(f[0], f[400], INF);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '#')
                continue;
            f[i * w + j][i * w + j] = 0;
            for (int k = 0; k < 4; ++k) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny < 0 || nx < 0 || ny >= h || nx >= w || s[ny][nx] == '#')
                    continue;
                f[i * w + j][ny * w + nx] = 1;
            }
        }
    }
    // print();

    for (int k = 0; k < h * w; ++k) {
        for (int i = 0; i < h * w; ++i) {
            for (int j = 0; j < h * w; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    // print();

    int ans = 0;
    for (int i = 0; i < h * w; ++i) {
        for (int j = 0; j < h * w; ++j) {
            if (f[i][j] < INF)
                ans = max(ans, f[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}