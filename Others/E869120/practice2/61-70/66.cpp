#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

class UnionFind {
    vector<int> data;
public:
    UnionFind(int size = 0) {
        resize(size);
    }
    void resize(int size) {
        data.resize(size, -1);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y)
            return;
        if (data[y] < data[x])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int count() {
        int cnt = 0;
        for (int i = 0, n = data.size(); i < n; ++i) {
            if (i == root(i))
                cnt++;
        }
        return cnt;
    }
};

using T = tuple<double, int, int>;

int n;
double x[100], y[100], z[100], r[100];
double d[100][100];

void solve() {
    fill(d[0], d[n], 0);
    UnionFind uf(n);
    priority_queue<T, vector<T>, greater<T>> que;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            d[i][j] = max(0.0, sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2) + pow(z[i] - z[j], 2)) - r[i] - r[j]);
            que.emplace(d[i][j], i, j);
        }
    }
    double ans = 0;
    while (!que.empty()) {
        auto [di, u, v] = que.top();
        que.pop();
        if (uf.root(u) == uf.root(v))
            continue;
        uf.unite(u, v);
        ans += di;
    }
    cout << fixed << setprecision(3);
    cout << ans << endl;
}

int main() {
    while (cin >> n && n > 0) {
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i] >> z[i] >> r[i];
        }
        solve();
    }

    return 0;
}