#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> void chmax(T& a, T b){ a>b?:a=b; }
template<class T> void chmin(T& a, T b){ a<b?:a=b; }

ll dp[2001][2001];

int main() {
    int n;
    ll a[2000];
    pair<ll, int> p[2000];
    cin >> n;
    rep(i, n) {
        cin >> a[i];
        p[i].first = a[i];
        p[i].second = i;
    }
    sort(p, p + n, greater<pair<ll, int>>());

    fill(dp[0], dp[2001], -1);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int l = 0; l <= i; ++l) {
            int r = i - l;
            chmax(dp[l + 1][r], dp[l][r] + p[i].first * abs(p[i].second - l));
            chmax(dp[l][r + 1], dp[l][r] + p[i].first * abs(p[i].second - (n - r - 1)));
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i)
        chmax(ans, dp[i][n - i]);
    cout << ans << endl;

    return 0;
}