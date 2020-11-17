#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

ll dp[2000][2000];
ll wp[2000][2000][3];
int h, w;
string f[2000];

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        cin >> f[i];
    }

    dp[0][0] = 1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (f[i][j] == '#') {
                wp[i][j][0] = 0;
                wp[i][j][1] = 0;
                wp[i][j][2] = 0;
                continue;
            }
            if (i > 0) {
                (wp[i][j][0] += wp[i - 1][j][0] + dp[i - 1][j]) %= MOD;
                (dp[i][j] += wp[i][j][0]) %= MOD;
            }
            if (j > 0) {
                (wp[i][j][1] += wp[i][j - 1][1] + dp[i][j - 1]) %= MOD;
                (dp[i][j] += wp[i][j][1]) %= MOD;
            }
            if (i > 0 && j > 0) {
                (wp[i][j][2] += wp[i - 1][j - 1][2] + dp[i - 1][j - 1]) %= MOD;
                (dp[i][j] += wp[i][j][2]) %= MOD;
            }
        }
    }

    cout << dp[h - 1][w - 1] << endl;

    return 0;
}