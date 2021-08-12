#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

ll pow_mod(ll a, ll b, ll p) {
    if (b == 0) return 1;
    if (b % 2) return (a * pow_mod(a, b - 1, p)) % p;
    return pow_mod(a * a % p, b / 2, p);
}

ll n;

ll cnt(ll a, ll b, ll k) {
    ll t = 0;
    for (ll i = 1; i <= a; ++i) {
        for (ll j = 1; j <= b; ++j) {
            t += pow_mod(2, n - 1 - j - i * (n / k + 1), MOD);
        }
    }
    return t;
}

int main() {
    cin >> n;
    ll sum = 0, allb = pow_mod(2, n, MOD);
    for (ll k = 1; k <= n; ++k) {
        ll t = allb - cnt(n % k, n / k, k) - cnt(k - n % k, n / k - 1, k);
        (sum += t) % MOD;
        cout << sum << endl;
    }

    return 0;
}