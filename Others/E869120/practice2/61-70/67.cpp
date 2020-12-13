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

using P = pair<int, int>;
using T = tuple<int, int, int>;

int main() {
    int n, x, y;
    cin >> n;
    vector<P> vx, vy;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        vx.emplace_back(x, i);
        vy.emplace_back(y, i);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vector<T> e;
    for (int i = 0; i < n - 1; ++i) {
        e.emplace_back(vx[i + 1].first - vx[i].first, vx[i].second, vx[i + 1].second);
        e.emplace_back(vy[i + 1].first - vy[i].first, vy[i].second, vy[i + 1].second);
    }
    // いらない
    for (int i = 1; i < n; ++i) {
        e.emplace_back(vx[i].first - vx[i - 1].first, vx[i - 1].second, vx[i].second);
        e.emplace_back(vy[i].first - vy[i - 1].first, vy[i - 1].second, vy[i].second);
    }
    sort(e.begin(), e.end());

    UnionFind uf(n);
    ll ans = 0;
    for (auto t : e) {
        auto [co, u, v] = t;
        if (uf.root(u) == uf.root(v))
            continue;
        uf.unite(u, v);
        ans += co;
    }

    cout << ans << endl;

    return 0;
}