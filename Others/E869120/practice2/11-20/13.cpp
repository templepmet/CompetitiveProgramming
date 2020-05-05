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

int a[10][10000];

int main() {
    int r, c;
    cin >> r >> c;
    rep(i, r)rep(j, c)cin >> a[i][j];

    int ans = 0;
    for (int i = 0; i < (1 << r); ++i) {
        int cnt = 0;
        for (int j = 0; j < c; ++j) {
            int z = 0, o = 0, t;
            for (int k = 0; k < r; ++k) {
                t = a[k][j];
                if (i & (1 << k)) {
                    t = !t;
                }
                if (t)
                    o++;
                else
                    z++;
            }
            cnt += max(z, o);
        }
        chmax(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}