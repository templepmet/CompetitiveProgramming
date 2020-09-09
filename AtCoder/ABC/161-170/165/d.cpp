#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> void chmax(T& a, T b){ if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b){ if (a > b) { a = b; } }

ll a, b, n;

ll f(ll x) {
    return ((a * x) / b - a * (x / b));
}

int main() {
    cin >> a >> b >> n;
    ll l = 1, r = n, ans = -1;
    bool update = 1;
    while (update) {
        update = 0;
        if (f((l * 2 + r) / 3) > f((l + r * 2) / 3)) {
            r = (l + r * 2) / 3;
        }
        else {
            l = (l * 2 + r) / 3;
        }
        if (ans < f(l)) {
            ans = f(l);
            update = 1;
        }
        if (ans < f(r)) {
            ans = f(r);
            update = 1;
        }
    }
    cout << ans << endl;

    return 0;
}