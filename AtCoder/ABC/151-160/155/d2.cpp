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

int n;
ll k, a[200000];

// o(nlogn)
bool check(ll x) {
    ll cnt = 0;
    int suf;
    for (int i = 0; i < n; ++i) { // 積がx未満
        if (a[i] < 0) {
            if (x > 0) {
                if (x % a[i] == 0)
                    suf = upper_bound(a, a + n, x / a[i]) - a;
                else
                    suf = lower_bound(a, a + n, x / a[i]) - a;
                cnt += n - max(i + 1, suf);
            }
            else {
                suf = upper_bound(a, a + n, x / a[i]) - a;
                cnt += n - suf;
            }
        }
        else if (a[i] > 0) {
            if (x > 0) {
                if (x % a[i] == 0)
                    suf = lower_bound(a, a + n, x / a[i]) - 1 - a;
                else
                    suf = upper_bound(a, a + n, x / a[i]) - 1 - a;
                cnt += max(0, suf - i);
            }
            else {
                cnt += 0; // i < jで存在しない
            }
        }
        else if (x > 0) { // a[i] == 0
            cnt += n - i - 1;
        }
    }
    if (cnt < k)
        return true;
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    ll l = -1e18, r = 1e18 + 1, mid; // l:ok, r:ng
    while (l + 1 < r) { // l + 1 == r となったら終了
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l << endl;

    return 0;
}