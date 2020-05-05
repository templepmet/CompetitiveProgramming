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

#define MAX_N 200000

ll cnt[MAX_N + 1];
vector<int> g[MAX_N + 1];

void dfs(int par, int u, ll sum) {
    cnt[u] += sum;
    for (int v : g[u]) {
        if (v == par)
            continue;
        dfs(u, v, cnt[u]);
    }
}

int main() {
    int n, q, a, b, p, x;
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    while (q--) {
        cin >> p >> x;
        cnt[p] += x;
    }
    dfs(0, 1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << cnt[i];
        if (i < n)
            cout << " ";
    }
    cout << endl;

    return 0;
}