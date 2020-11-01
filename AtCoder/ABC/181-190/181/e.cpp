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

int n, m;
int h[200000], w[200000];

ll b[200002];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> w[i];
    }
    sort(h, h + n);
    // 境界
    for (int i = 2; i <= n; ++i) {
        b[i] = b[i - 2] + abs(h[i - 2] - h[i - 1]);
    }
    ll ans = 1e18;
    for (int i = 0; i < m; ++i) {
        int p = lower_bound(h, h + n, w[i]) - h - 1;
        ll t = 0;
        if (p % 2) {
            t += b[p + 1] - b[0];
            t += abs(w[i] - h[p + 1]);
            t += b[n] - b[p + 2];
        }
        else {
            t += b[p] - b[0];
            t += abs(w[i] - h[p]);
            t += b[n] - b[p + 1];
        }
        chmin(ans, t);
    }
    cout << ans << endl;

    return 0;
}