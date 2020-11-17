#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

class UnionFind {
    public:
    vector<int> data;
    vector<map<int, int>> mp;
    UnionFind(int size = 0) {
        resize(size);
    }
    void resize(int size) {
        data.resize(size, -1);
        mp.resize(size);
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

        for (auto t : mp[y]) {
            mp[x][t.first] += t.second;
        }
        mp[y].clear();
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

int c[200000];

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        uf.mp[i][c[i] - 1]++;
    }
    int m, a, b;
    while (q--) {
        cin >> m >> a >> b;
        a--; b--;
        if (m == 1) {
            uf.unite(a, b);
        }
        else {
            cout << uf.mp[uf.root(a)][b] << endl;
        }
    }

    return 0;
}