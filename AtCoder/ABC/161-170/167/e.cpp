#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 998244353

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> void chmax(T& a, T b){ a>b?:a=b; }
template<class T> void chmin(T& a, T b){ a<b?:a=b; }

ll dp[200001];

ll pow(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2) return a * pow(a, b - 1);
    return pow(a * a, b / 2);
}

//a^(-1)≡a^(p-2) (mod p) (but p is prime)
ll powMod(ll a, ll b, ll p) {
    if (b == 0) return 1;
    if (b % 2) return (a * powMod(a, b - 1, p)) % p;
    return powMod(a * a % p, b / 2, p);
}

int main() {
    ll n, m, k, ans = 0, c = 1;
    cin >> n >> m >> k;
    for (int i = 0; i <= k; ++i) {
        ll t = 1;
        (t *= m) %= MOD;
        (t *= powMod(m - 1, n - i - 1, MOD)) %= MOD;
        (t *= c) %= MOD;
        (ans += t) %= MOD;
        (c *= n - i - 1) %= MOD;
        (c *= powMod(i + 1, MOD - 2, MOD)) %= MOD;
    }
    cout << ans << endl;

    return 0;
}