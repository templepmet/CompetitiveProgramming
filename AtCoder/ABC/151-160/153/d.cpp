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

map<ll, ll> mp;

ll rec(ll n) {
    if (n == 1)
        return 1;
    if (mp[n] > 0)
        return mp[n];
    return mp[n] = 1 + rec(n / 2) * 2;
}

int main() {
    ll h;
    cin >> h;
    cout << rec(h) << endl;

    return 0;
}