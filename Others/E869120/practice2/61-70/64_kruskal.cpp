#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

using T = tuple<int, int, int>;

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

int main() {
    int v, e, s, t, w;
    priority_queue<T, vector<T>, greater<T>> q;
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        cin >> s >> t >> w;
        q.emplace(w, s, t);
    }

    int ans = 0;
    UnionFind uf(v);
    while (!q.empty()) {
        auto [w, s, t] = q.top();
        q.pop();
        if (uf.root(s) == uf.root(t))
            continue;
        uf.unite(s, t);
        ans += w;
    }
    cout << ans << endl;

    return 0;
}