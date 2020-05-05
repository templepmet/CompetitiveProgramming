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
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n), d(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll sum = 0, ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        sum += c.end() - upper_bound(all(c), b[i]);
        d[i] = sum;
    }
    for (int i = 0; i < n; ++i) {
        ans += d[upper_bound(all(b), a[i]) - b.begin()];
    }
    cout << ans << endl;

    return 0;
}