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

map<ll, int> cnt;

void prime_factor(ll n) {
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            cnt[i]++;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n != 1)
        cnt[n]++;
}

int main() {
    ll a, b;
    cin >> a >> b;
    prime_factor(a);
    prime_factor(b);
    int ans = 1;
    for (auto t : cnt) {
        if (t.second == 2)
            ans++;
    }
    cout << ans << endl;

    return 0;
}
