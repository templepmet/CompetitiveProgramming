#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

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

/*

// rmq (min)
auto fx = [](int x1, int x2) -> int { return min(x1, x2); };
SegmentTree<int> rmq(n, fx, INF);

*/

using P = pair<int, int>;

int main() {
    int n, a;
    cin >> n;

    auto fx = [](P x1, P x2) -> P { return max(x1, x2); };
    SegmentTree<P> rmq(1 << n, fx, make_pair(0, 0));

    for (int i = 0; i < 1 << n; ++i) {
        cin >> a;
        rmq.set(i, make_pair(a, i));
    }
    rmq.build();
    cout << min(rmq.dat[1], rmq.dat[2]).second + 1 << endl;

    return 0;
}