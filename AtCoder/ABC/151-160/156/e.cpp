#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

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
    ll n, k, ans = 1, c1 = 1, c2 = 1;
    cin >> n >> k;
    ll cnt = (n < k ? n - 1 : k);
    for (int i = 1; i <= cnt; ++i) {
        (c1 *= (n - i + 1)) %= MOD7;
        (c1 *= powMod(i, MOD7 - 2, MOD7)) %= MOD7;
        (c2 *= (n - i)) %= MOD7;
        (c2 *= powMod(i, MOD7 - 2, MOD7)) %= MOD7;
        (ans += (c1 * c2) % MOD7) %= MOD7;
    }
    cout << ans << endl;

    return 0;
}