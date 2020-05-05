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

ll n, m;
ll a[100000];
ll b[100001];

bool is_ok(ll x) {
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += n - (lower_bound(a, a + n, x - a[i]) - a);
    }
    if (cnt >= m)
        return true;
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    ll l = 0, r = 200000, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (is_ok(mid)) { // m以上ある→midが小さすぎる
            l = mid + 1;
        }
        else { // m以上ない→midが大きすぎる
            r = mid - 1;
        }
    }
    // l-1がm以上存在できる最小の境界
    // (l-1+1=l)がm以下になる
    // 残りは丁度l-1の数
    
    for (int i = 1; i <= n; ++i) {
        b[i] += b[i - 1] + a[i - 1];
    }
    ll cnt = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        int s = lower_bound(a, a + n, l - a[i]) - a;
        cnt += n - s;
        sum += b[n] - b[s] + (n - s) * a[i];
    }
    if (m > cnt) {
        sum += (m - cnt) * (l - 1);
    }
    cout << sum << endl;

    return 0;
}