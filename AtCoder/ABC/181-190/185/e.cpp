#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int dp[1010][1010];
int a[1000], b[1000];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    fill(dp[0], dp[1010], INF);
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= m; ++i) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            chmin(dp[i][j], dp[i - 1][j] + 1);
            chmin(dp[i][j], dp[i][j - 1] + 1);
            if (a[i - 1] == b[j - 1]) {
                chmin(dp[i][j], dp[i - 1][j - 1]);
            }
            else {
                chmin(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}