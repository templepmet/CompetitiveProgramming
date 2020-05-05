#include <iostream>
#include <algorithm>

using namespace std;

#define MOD (int)(1e9 + 7)

using ll = long long;

ll powMod(ll x, int k) {
    if (k == 0)
        return 1;
    if (k % 2 == 0)
        return powMod(x * x % MOD, k / 2);
    else
        return x * powMod(x, k - 1) % MOD;
}

int calc(int a, int b) {
    ll t = 1, av = 1, bv = 1;
    for (int i = 1; i <= a + b; ++i)
        (t *= i) %= MOD;
    for (int i = 1; i <= a; ++i)
        (av *= i) %= MOD;
    for (int i = 1; i <= b; ++i)
        (bv *= i) %= MOD;
    (t *= powMod(av, MOD - 2)) %= MOD;
    (t *= powMod(bv, MOD - 2)) %= MOD;
    return t;
}

int main() {
    int x, y;
    ll ans = 0;
    cin >> x >> y;
    for (int i = 0; i <= y && i * 2 <= x; ++i) {
        if (y - i == 2 * (x - 2 * i))
            (ans += calc(i, x - 2 * i)) %= MOD;
    }
    cout << ans << endl;

    return 0;
}