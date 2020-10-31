#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

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

int n, m, c, d;
int a[200000];
int b[200000];
ll sum[200000];

int main() {
    cin >> n >> m;
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> c >> d;
        uf.unite(c - 1, d - 1);
    }
    for (int i = 0; i < n; ++i) {
        sum[uf.root(i)] += a[i] - b[i];
    }
    bool f = true;
    for (int i = 0; i < n; ++i) {
        if (sum[i] != 0)
            f = false;
    }
    cout << (f ? "Yes" : "No") << endl;

    return 0;
}