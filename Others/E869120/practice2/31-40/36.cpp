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

int dp[10001];

int main() {
    int n, W, w, v;
    cin >> n >> W;
    fill(dp, dp + W + 1, -1);
    dp[0] = 0;
    rep(i, n) {
        cin >> v >> w;
        for (int j = 0; j < W; ++j) {
            if (dp[j] >= 0 && j + w <= W) {
                chmax(dp[j + w], dp[j] + v);
            }
        }
    }
    cout << *max_element(dp, dp + W + 1) << endl;

    return 0;
}