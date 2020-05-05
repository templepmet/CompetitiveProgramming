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

#include <cassert>

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll minus = lower_bound(a.begin(), a.end(), 0LL) - a.begin();
    ll plus = n - minus;
    vector<ll> mv(minus);
    vector<ll> pv(plus);
    for (int i = 0; i < minus; ++i)
        mv[i] = -a[minus - i - 1];
    for (int i = 0; i < plus; ++i)
        pv[i] = a[minus + i];
    if (k <= minus * plus) { // -になる場合
        k--;
        ll y = k / plus;
        ll x = k % plus;
        cout << -mv[minus - y - 1] * pv[plus - x - 1] << endl;
    }
    else { // +になる場合
        ll rank = minus * plus;
        ll mi = 0, pi = 0;
        while (1) {
            if (mi < minus - 1 && mv[mi] * mv[minus - 1] < pv[pi] * pv[plus - 1]) {
                if (k <= rank + minus - mi - 1)
                    break;
                rank += (minus - mi - 1);
                mi++;
            }
            else if (pi < plus - 1) {
                if (k <= rank + plus - pi - 1)
                    break;
                rank += (plus - pi - 1);
                pi++;
            }
            else {
                assert(0 == 1);
            }
        }
        vector<ll> t;
        for (int i = minus - 1; i > mi; --i)
            t.push_back(mv[mi] * mv[i]);
        for (int i = plus - 1; i > pi; --i)
            t.push_back(pv[pi] * pv[i]);
        sort(t.begin(), t.end());
        cout << t[k - rank - 1] << endl;
    }

    return 0;
}