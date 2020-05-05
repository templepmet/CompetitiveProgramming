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

vector<int> g[100000];

void dfs(vector<int> &d, int u, int v, int l) {
    d[v] = l;
    for (auto t : g[v]) {
        if (t == u)
            continue;
        dfs(d, v, t, l + 1);
    }
}

int main() {
    int n, u, v, a, b;
    cin >> n >> u >> v;
    u--; v--;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> d_u(n, 0), d_v(n, 0);
    dfs(d_u, u, u, 0);
    dfs(d_v, v, v, 0);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (d_u[i] < d_v[i])
            ans = max(ans, d_u[i] + (d_v[i] - d_u[i]) - 1);
    }
    cout << ans << endl;

    return 0;
}