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

#define MAXN 1000001
#define MOD 998244353

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

vector<ll> a[MAXN];
ll n, k[MAXN], cnt[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        a[i].resize(k[i]);
        for (int j = 0; j < k[i]; ++j) {
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }
    }
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k[i]; ++j) {
            ll t = cnt[a[i][j]];
            (t *= powMod(n, MOD - 2, MOD)) %= MOD;
            (t *= powMod(n, MOD - 2, MOD)) %= MOD;
            (t *= powMod(k[i], MOD - 2, MOD)) %= MOD;
            (sum += t) %= MOD;
        }
    }
    cout << sum << endl;

    return 0;
}