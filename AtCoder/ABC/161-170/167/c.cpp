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
    int n, m, x, c[12], a[12][12];
    cin >> n >> m >> x;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int ans = INF;
    for (int t = 0; t < (1 << n); ++t) {
        int sum = 0, b[12] = { 0 };
        for (int i = 0; i < n; ++i) {
            if (t & (1 << i)) {
                sum += c[i];
                for (int j = 0; j < m; ++j) {
                    b[j] += a[i][j];
                }
            }
        }
        bool f = true;
        for (int i = 0; i < m; ++i) {
            if (b[i] < x)
                f = false;
        }
        if (f) {
            ans = min(ans, sum);
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}