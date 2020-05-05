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

ll n, m, v, p;
int a[100000];

bool isok(int s) {
    ll sum = 0;
    for (int i = n - 1, j = 0; i >= 0; --i) {
        if (i == s)
            continue;
        if (j < p - 1 || i < s) {
            sum += m;
        }
        else {
            if (a[s] + m < a[i])
                return false;
            sum += (a[s] + m - a[i]);
        }
        j++;
    }
    if (sum >= m * (v - 1))
        return true;
    return false;
}

int main() {
    cin >> n >> m >> v >> p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    int l = 0, r = n - 1, mid, ans;
    while (l <= r) {
        mid = (l + r) / 2;
        if (isok(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
            ans = l;
        }
    }
    cout << n - ans << endl;

    return 0;
}