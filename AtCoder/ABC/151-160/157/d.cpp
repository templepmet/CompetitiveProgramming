#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

int n, m, k;
vector<int> g[100000];
int f[100000];
int fb[100000];
int color[100000];
int group[100000];

void dfs(int i, int col) {
    color[i] = col;
    for (auto t : g[i]) {
        if (color[t] == 0) {
            dfs(t, col);
        }
    }
}

int main() {
    int a, b;
    cin >> n >> m >> k;
    while (m--) {
        cin >> a >> b;
        a--; b--;
        f[a]++;
        f[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
    int col = 1;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(i, col++);
        }
    }
    while (k--) {
        cin >> a >> b;
        a--; b--;
        if (color[a] == color[b] && binary_search(g[a].begin(), g[a].end(), b) == false) {
            fb[a]++;
            fb[b]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        group[color[i] - 1]++;
    }
    for (int i = 0; i < n; ++i) {
        cout << max(0, group[color[i] - 1] - f[i] - fb[i] - 1);
        if (i < n - 1)
            cout << " ";
        // cout << group[color[i] - 1] << " " << f[i] << " " << fb[i] << endl;
    }
    cout << endl;

    return 0;
}

// 連結している人数-連結して友達もしくはブロックの人数-自身の人数（１）
// ＝連結している人数-友達の人数-連結成分かつブロックで友達でない人数-自身の人数（１）