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

int n;
ll b[500001];

// 1-indexed

void add(int id, ll a) {
    for (int i = id; i <= n; i += (i & -i)) {
        b[i] += a;
    }
}

ll sum(int id) {
    ll v = 0;
    for (int i = id; i > 0; i -= (i & -i)) {
        v += b[i];
    }
    return v;
}

// closed
ll sum(int a, int b) {
    return sum(b) - sum(a - 1);
}

int main() {
    int q, m, p, l, r;
    ll a;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        add(i + 1, a);
    }
    while (q--) {
        cin >> m;
        if (m) {
            cin >> l >> r;
            cout << sum(l + 1, r) << endl;
        }
        else {
            cin >> p >> a;
            add(p + 1, a);
        }
    }

    return 0;
}