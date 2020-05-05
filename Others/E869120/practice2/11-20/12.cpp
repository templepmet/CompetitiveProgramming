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

int main() {
    int n, m, x, y, a[12][12] = {};
    cin >> n >> m;
    rep(i, m) {
        cin >> x >> y;
        x--; y--;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        int cnt = 0, f = 1;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                cnt++;
                for (int k = j + 1; k < n; ++k) {
                    if (i & (1 << k)) {
                        if (a[j][k] == 0)
                            f = 0;
                    }
                }
            }
        }
        if (f)
            chmax(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}