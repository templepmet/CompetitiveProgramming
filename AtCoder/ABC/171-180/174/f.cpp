#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> void chmax(T& a, T b){ a>b?:a=b; }
template<class T> void chmin(T& a, T b){ a<b?:a=b; }

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
    int n, q;
    cin >> n >> q;

    vector<int> c(n);
    list<int> v[n + 1];
    auto fx = [](int x1, int x2) -> int { return x1 + x2; };
    SegmentTree<int> rsq(n, fx, 0);
    
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if (v[c[i]].size() == 0) {
            rsq.set(i, 1);
        }
        v[c[i]].push_back(i);
    }
    rsq.build();

    map<pair<int, int>, int> mp;
    vector<pair<int, int>> lr(q), lrs(q);
    for (int i = 0; i < q; ++i) {
        cin >> lr[i].first >> lr[i].second;
        lrs[i] = lr[i];
    }
    sort(all(lrs));
    int bl = 0;
    for (int i = 0; i < q; ++i) {
        for (int j = bl; j < lrs[i].first - 1; ++j) {
            v[c[j]].pop_front();
            if (v[c[j]].size() > 0)
                rsq.update(*v[c[j]].begin(), 1);
        }
        bl = lrs[i].first - 1;
        mp[lrs[i]] = rsq.query(lrs[i].first - 1, lrs[i].second);
    }

    for (int i = 0; i < q; ++i) {
        cout << mp[lr[i]] << endl;
    }   

    return 0;
}