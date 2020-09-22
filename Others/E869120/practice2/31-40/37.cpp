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

int dp[50001];

int main() {
    int n, m, c;
    cin >> n >> m;
    fill(dp, dp + n + 1, INF);
    dp[0] = 0;
    rep(i, m) {
        cin >> c;
        for (int j = 0; j < n; ++j) {
            if (dp[j] < INF && j + c <= n)
                chmin(dp[j + c], dp[j] + 1);
        }
    }
    cout << dp[n] << endl;

    return 0;
}