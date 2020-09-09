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

int a[200000];
int b[200000];
ll c[200001];
ll d[200001];

int main() {
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        c[i + 1] = c[i] + a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        d[i + 1] = d[i] + b[i];
    }
    for (int i = 0; i <= n; ++i) {
        if (c[i] > k)
            continue;
        int t = upper_bound(d, d + m + 1, k - c[i]) - d;
        chmax(ans, i + t - 1);
    }
    cout << ans << endl;

    return 0;
}