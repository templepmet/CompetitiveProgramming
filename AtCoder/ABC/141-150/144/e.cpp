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
ll k;
ll a[200000], f[200000];

bool isok(ll m) {
    ll sum = 0, t;
    for (int i = 0; i < n; ++i) {
        t = (a[i] * f[i] - m + f[i] - 1) / f[i];
        sum += max(0LL, t);
    }
    if (sum <= k)
        return true;
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    sort(a, a + n);
    sort(f, f + n, greater<ll>());

    ll l = -1, r = 1e12, m;
    while (r - l > 1) {
        m = (l + r) / 2;
        if (isok(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << r << endl;

    return 0;
}