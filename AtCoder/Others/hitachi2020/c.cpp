#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

int n;
vector<int> g[200000];
int color[200000];
int ans[200000];
int used[200001];

void dfs(int u, int b, int d) {
    color[u] = d;
    for (auto v : g[u]) {
        if (v == b)
            continue;
        dfs(v, u, !d);
    }
}

int main() {
    int a, b;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, 0, 0);

    int e = count(color, color + n, 0);
    int o = count(color, color + n, 1);
    if (min(e, o) <= n / 3) {
        int k = (e < o ? 0 : 1);
        for (int i = 0, c = 3; i < n; ++i) {
            if (color[i] == k) {
                ans[i] = c;
                used[c] = 1;
                c += 3;
            }
        }
        for (int i = 0, c = 1; i < n; ++i) {
            if (ans[i] == 0) {
                while (used[c])
                    c++;
                ans[i] = c;
                used[c] = 1;
            }
        }
    }
    else {
        for (int i = 0, c1 = 1, c2 = 2; i < n; ++i) {
            if (color[i] == 0 && c1 <= n) {
                ans[i] = c1;
                used[c1] = 1;
                c1 += 3;
            }
            else if (color[i] == 1 && c2 <= n) {
                ans[i] = c2;
                used[c2] = 1;
                c2 += 3;
            }
        }
        for (int i = 0, c = 3; i < n; ++i) {
            if (ans[i] == 0) {
                while (used[c])
                    c += 3;
                ans[i] = c;
                used[c] = 1;
            }
        }
    }

    cout << ans[0];
    for (int i = 1; i < n; ++i) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}