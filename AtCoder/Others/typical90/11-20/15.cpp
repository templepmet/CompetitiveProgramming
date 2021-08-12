#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

ll pow_mod(ll a, ll b, ll p) {
    if (b == 0) return 1;
    if (b % 2) return (a * pow_mod(a, b - 1, p)) % p;
    return pow_mod(a * a % p, b / 2, p);
}

ll cnt(ll n) {
    // return n * (n + 1) / 2;
    return pow_mod(2, n, MOD) - 1;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> ans(n + 1, 0);
    for (int k = n; k >= 1; --k) {
        ll t1 = (n % k) * cnt(n / k + 1);
        ll t2 = (k - n % k) * cnt(n / k);
        ll t = t1 + t2;
        // ll t = (n / k + 1) * ((n / k) * k + 2 * (n % k)) / 2;
        ans[k - 1] = (0 + t) % MOD;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}