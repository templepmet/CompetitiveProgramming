#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

double dp[101][101][101];

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    dp[a][b][c] = 1;
    for (int i = a; i < 100; ++i) {
        for (int j = b; j < 100; ++j) {
            for (int k = c; k < 100; ++k) {
                dp[i + 1][j][k] += dp[i][j][k] * i / (i + j + k);
                dp[i][j + 1][k] += dp[i][j][k] * j / (i + j + k);
                dp[i][j][k + 1] += dp[i][j][k] * k / (i + j + k);
            }
        }
    }
    double ans = 0;
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            for (int k = 0; k <= 100; ++k) {
                if (i == 100 || j == 100 || k == 100) {
                    if (dp[i][j][k] > 0)
                        ans += dp[i][j][k] * (i + j + k - (a + b + c));
                }
            }
        }
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;

    return 0;
}

// 残り操作回数の期待値がポイント