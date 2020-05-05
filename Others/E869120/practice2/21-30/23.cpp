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

int a[1000000];

int main() {
    int n, m, p[1000], ans = 0;
    cin >> n >> m;
    rep(i, n) {
        cin >> p[i];
        if (p[i] <= m)
            chmax(ans, p[i]);
    }
    rep(i, n) {
        rep(j, n) {
            a[i * n + j] = p[i] + p[j];
            if (a[i * n + j] <= m)
                chmax(ans, a[i * n + j]);
        }
    }
    sort(p, p + n);
    sort(a, a + n * n);
    rep(i, n * n) {
        int s = upper_bound(p, p + n, m - a[i]) - p;
        if (s > 0)
            chmax(ans, a[i] + p[s - 1]);
        s = upper_bound(a, a + n * n, m - a[i]) - a;
        if (s > 0)
            chmax(ans, a[i] + a[s - 1]);
    }
    cout << ans << endl;


    return 0;
}