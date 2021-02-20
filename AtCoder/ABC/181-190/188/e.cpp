#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

/*
    g: 0-index vertices
*/
vector<int> topological_sort(vector<vector<int>> &g) {
    int n = g.size();
    vector<int> in(n, 0), ret;
    for (int i = 0; i < n; ++i) {
        for (auto v : g[i]) {
            in[v]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        ret.push_back(u);
        for (auto v : g[u]) {
            in[v]--;
            if (in[v] == 0) {
                que.push(v);
            }
        }
    }
    return ret;
}

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n, m, x, y;
    cin >> n >> m;
    vector<int> a(n), in(n, 0);
    vector<vector<int>> g(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        r[y].push_back(x);
    }
    vector<int> v = topological_sort(g), w(n);
    for (int i = 0; i < n; ++i) {
        w[i] = a[v[i]];
    }
    int ans = -1e9;
    for (int i = 0; i < n; ++i) {
        int minv = 2e9;
        int u = v[i];
        for (auto t : r[u]) {
            chmin(minv, a[t]);
        }
        if (minv < 2e9) {
            chmax(ans, a[u] - minv);
            chmin(a[u], minv);
        }
    }
    cout << ans << endl;

    return 0;
}