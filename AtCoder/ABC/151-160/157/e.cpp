#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

template <typename X>
struct SegmentTree {
    using FX = function<X(X, X)>;
    int n;
    FX fx;
    const X ex;
    vector<X> dat;
    SegmentTree(int n_, FX fx_, X ex_) : fx(fx_), ex(ex_) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
        dat.resize(n * 2, ex);
    }

    X get(int i) {
        return dat[i + n - 1];
    }
    void set(int i, X x) {
        dat[i + n - 1] = x;
    }
    void build() {
        for (int i = n - 2; i >= 0; --i) {
            dat[i] = fx(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }
    void update(int i, X x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    X query(int a, int b) {
        return query_sub(a, b, 0, 0, n);
    }
    X query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return ex;
        }
        else if (a <= l && r <= b) {
            return dat[k];
        }
        else {
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
};

int main() {
    int n, q, qq, i, l, r;
    char c;
    string s;
    cin >> n >> s >> q;
    SegmentTree<int> rsq(n,
    [](int x1, int x2) -> int { return x1 | x2; },
    0 );
    for (int j = 0; j < n; ++j) {
        rsq.set(j, 1 << (s[j] - 'a'));
    }
    rsq.build();
    while (q--) {
        cin >> qq;
        if (qq == 1) {
            cin >> i >> c;
            i--;
            rsq.update(i, 1 << (c - 'a'));
        }
        else {
            cin >> l >> r;
            int t = rsq.query(l - 1, r);
            int cnt = 0;
            while (t > 0) {
                cnt += (t & 1);
                t >>= 1;
            }
            cout << cnt << endl;
        }
    }

    return 0;
}