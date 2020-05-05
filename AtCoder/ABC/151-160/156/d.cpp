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

ll combi(ll n, ll r) {
    ll ret = 1;
    for (int i = 0; i < r; ++i) {
        (ret *= n - i) %= MOD7;
        (ret *= powMod(i + 1, MOD7 - 2, MOD7)) %= MOD7;
    }
    return ret;
}

int main() {
    ll n, a, b, ans = 0;
    cin >> n >> a >> b;
    ans += powMod(2, n, MOD7);
    (ans += MOD7 - 1) %= MOD7;
    (ans += MOD7 - combi(n, a)) %= MOD7;
    (ans += MOD7 - combi(n, b)) %= MOD7;
    cout << ans << endl;

    return 0;
}