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

int main() {
    int n;
    ll d, a, ans = 0;
    cin >> n >> d >> a;
    vector<pair<ll, ll>> v(n);
    vector<ll> sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        if (i > 0)
            sum[i] += sum[i - 1];
        ll val = v[i].second - sum[i];
        if (val > 0) {
            ll cnt = val / a + (val % a > 0);
            ans += cnt;
            int suf = upper_bound(v.begin(), v.end(), make_pair(v[i].first + d * 2, INFL)) - v.begin();        
            sum[i] += cnt * a;
            sum[suf] -= cnt * a;
        }
    }
    cout << ans << endl;

    return 0;
}