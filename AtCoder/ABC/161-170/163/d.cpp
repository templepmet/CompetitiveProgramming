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
    ll n, k;
    ll ans = 0;
    cin >> n >> k;
    for (ll i = k; i <= n + 1; ++i) {
        ll a = (i - 1) * i / 2;
        ll b = i * (2 * (n - i + 1) + i - 1) / 2;
        ans += max(0LL, b - a + 1);
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}