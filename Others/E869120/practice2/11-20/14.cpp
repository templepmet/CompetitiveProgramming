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
    int n, k, a[15];
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    ll ans = 1LL << 62;
    for (int i = 0; i < (1 << n); ++i) {
        int maxh = 0, cnt = 0;
        ll cost = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                cnt++;
                if (maxh >= a[j]) {
                    cost += maxh - a[j] + 1;
                    maxh++;
                }
            }
            chmax(maxh, a[j]);
        }
        if (cnt >= k)
            chmin(ans, cost);
    }
    cout << ans << endl;
    
    return 0;
}