#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

ll pow_mod(ll a, ll b, ll p) {
    if (b == 0) return 1;
    if (b % 2) return (a * pow_mod(a, b - 1, p)) % p;
    return pow_mod(a * a % p, b / 2, p);
}

ll inv_mod(ll a, ll p) {
    return pow_mod(a, p - 2, p);
}

ll combination(ll n, ll r, ll p = 0) {
    ll t = 1, d = 1;
    if (p == 0) {
        for (ll i = 1; i <= r; ++i) {
            t *= n--;
            t /= i;
        }
    }
    else {
        for (ll i = 1; i <= r; ++i) {
            t *= n--;
            t %= p;
            d *= i;
            d %= p;
        }
        t = (t * inv_mod(d, p)) % p;
    }
    return t;
}

ll homogenous(ll n, ll r, ll p = 0) {
    return combination(n + r - 1, r, p);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << homogenous(n, k, MOD) << endl;

    return 0;
}