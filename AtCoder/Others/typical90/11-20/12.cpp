#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[] = { 0, -1, 0, 1, -1, -1, 1, 1 };

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
    int h, w, q, a, b, c, d, op;
    cin >> h >> w >> q;
    vector<vector<int>> f(h, vector<int>(w, 0));
    UnionFind uf(h * w);

    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            a--; b--;
            f[a][b] = 1;
            for (int i = 0; i < 4; ++i) {
                int na = a + dy[i];
                int nb = b + dx[i];
                if (na < 0 || na >= h || nb < 0 || nb >= w)
                    continue;
                if (f[na][nb]) {
                    uf.unite(a * w + b, na * w + nb);
                }
            }
        }
        else {
            cin >> a >> b >> c >> d;
            a--; b--; c--; d--;
            if (f[a][b] && f[c][d] && uf.same(a * w + b, c * w + d)) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}