#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

int n, k;
ll a[100000];
ll fact[100000];
ll inv[100000];

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

ll combi(ll nn, ll kk) {
    if (nn < kk)
        return 0;
    return (((fact[nn] * inv[nn - kk]) % MOD7) * inv[kk]) % MOD7;
}

void pre() {
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD7;
        inv[i] = (inv[i - 1] * powMod(i, MOD7 - 2, MOD7)) % MOD7;
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    pre();

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (a[i] * combi(i, k - 1)) % MOD7;
        ans %= MOD7;
        ans -= (a[i] * combi(n - i - 1, k - 1)) % MOD7;
        ans %= MOD7;
    }
    if (ans < 0)
        ans += MOD7;
    cout << ans << endl;

    return 0;
}