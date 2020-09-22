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

int dp[1001][1001];

int main() {
    int q;
    string x, y;
    cin >> q;
    while (q--) {
        cin >> x >> y;
        int lx = x.size();
        int ly = y.size();
        fill(dp[0], dp[ly + 1], 0);
        for (int i = 1; i <= ly; ++i) {
            for (int j = 1; j <= lx; ++j) {
                chmax(dp[i][j], max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (y[i - 1] == x[j - 1])}));
            }
        }
        cout << dp[ly][lx] << endl;
    }

    return 0;
}