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

ll combination_mod(ll n, ll r, ll p) {
    ll t = 1, d = 1;
    for (ll i = 1; i <= r; ++i) {
        t *= n--;
        t %= p;
        d *= i;
        d %= p;
    }
    return (t * inv_mod(d, p)) % p;
}

int main() {
    int w, h;
    cin >> w >> h;
    w--; h--;
    cout << combination_mod(w + h, w, MOD) << endl;

    return 0;
}

// w+h C w = w+h C h