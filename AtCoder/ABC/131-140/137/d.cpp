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

int n, m, k, ans;
pair<int, int> a[100000];

vector<int> rmq;

void _update(int i) {
    rmq[i] = max(rmq[i * 2 + 1], rmq[i * 2 + 2]);
    if (i > 0)
        _update((i - 1) / 2);
}

void update(int i, int v) {
    rmq[i] = v;
    _update((i - 1) / 2);
}

void init() {
    k = 1;
    while (k < n)
        k *= 2;
    rmq.resize(k * 2);
    for (int i = 0; i < n; ++i) {
        update(i + k - 1, a[i].second);
    }
    rmq[k * 2 - 1] = 0;
}

int getmax(int i, int L, int R, int l, int r) {
    if (L <= l && r <= R)
        return i;
    if (l >= R || r <= l)
        return k * 2 - 1;
    int i1 = getmax(i * 2 + 1, L, R, l, (l + r) / 2);
    int i2 = getmax(i * 2 + 2, L, R, (l + r) / 2, r);
    if (rmq[i1] > rmq[i2])
        return i1;
    return i2;
}

int getsuf(int i, int v) {
    while (i < k - 1) {
        if (rmq[i * 2 + 1] == v)
            i = i * 2 + 1;
        else if (rmq[i * 2 + 2] == v)
            i = i * 2 + 2;
    }
    return i;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    init();
    for (int i = 1; i <= m; ++i) {
        int r = upper_bound(a, a + n, make_pair(i, INF)) - a;
        int maxi = getmax(0, 0, r, 0, k);
        if (rmq[maxi] > 0) {
            ans += rmq[maxi];
            update(getsuf(maxi, rmq[maxi]), 0);
        }
    }
    cout << ans << endl;

    return 0;
}