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

ll dp[100001];

int main() {
    ll n, k;
    ll ans = 0;
    cin >> n >> k;
    for (ll i = k; i >= 1; --i) {
        ll cnt = powMod(k / i, n, MOD);
        for(ll j = 2 * i; j <= k; j += i) {
            (cnt = cnt - dp[j] + MOD) %= MOD;
        }
        dp[i] = cnt % MOD;
        (ans += (cnt * i) % MOD) %= MOD;
    }
    cout << ans << endl;

    return 0;
}