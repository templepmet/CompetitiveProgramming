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

int t[1000000];

void factor(ll v) {
    for (int i = 2; i * i <= v; ++i) {
        int cnt = 0;
        while (v % i == 0) {
            cnt++;
            v /= i;
        }
        t[i] = max(t[i], cnt);
    }
    if (v != 1) {
        t[v] = max(t[v], 1);
    }
}

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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        factor(a[i]);
    }
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += powMod(a[i], MOD7 - 2, MOD7);
        sum %= MOD7;
    }
    for (int i = 0; i < 1000000; ++i) {
        if (t[i] > 0) {
            for (int j = 0; j < t[i]; ++j) {
                sum *= i;
                sum %= MOD7;
            }
        }
    }
    cout << sum << endl;

    return 0;
}