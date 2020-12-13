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

int main() {
    int n;
    while (cin >> n && n > 0) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll ans = 1;
        (ans *= (a - c - 1)) %= MOD;
        (ans *= (a + c)) %= MOD;
        (ans *= (b - d - 1)) %= MOD;
        (ans *= (b + d)) %= MOD;
        (ans *= inv_mod(4, MOD)) %= MOD;
        cout << ans << endl;
    }

    return 0;
}