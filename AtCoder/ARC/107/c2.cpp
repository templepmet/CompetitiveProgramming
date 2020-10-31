#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 998244353

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

ll fac(int n) {
    ll t = 1;
    for (int i = 1; i <= n; ++i) {
        t *= i;
        t %= MOD;
    }
    return t;
}

int main() {
    int n, k, a[50][50];
    cin >> n >> k;
    UnionFind uf1(n * n), uf2(n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int x = 0; x < n; ++x) {
        for (int y = x + 1; y < n; ++y) {
            bool f = true;
            for (int i = 0; i < n; ++i) {
                if (a[i][x] + a[i][y] > k) {
                    f = false;
                } 
            }
            if (f) {
                uf1.unite(x, y);
            }

            f = true;
            for (int j = 0; j < n; ++j) {
                if (a[x][j] + a[y][j] > k) {
                    f = false;
                }
            }
            if (f) {
                uf2.unite(x, y);
            }
        }
    }

    ll t1 = 1, t2 = 1;
    for (int i = 0; i < n * n; ++i) {
        if (i == uf1.root(i)) {
            (t1 *= fac(uf1.size(i))) %= MOD;
        }
        if (i == uf2.root(i)) {
            (t2 *= fac(uf2.size(i))) %= MOD;
        }
    }

    cout << (t1 * t2) % MOD << endl;

    return 0;
}