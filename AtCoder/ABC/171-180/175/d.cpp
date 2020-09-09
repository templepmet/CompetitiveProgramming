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

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> p(n), c(n), w(n + 1);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    rep(i, n) {
        cin >> c[i];
    }

    ll ans = -1e18;
    for (int i = 0; i < n; ++i) {
        int pos = i, cyc = 0;
        fill(all(w), 0);
        for (int j = 1; j <= n; ++j) {
            pos = p[pos];
            w[j] = w[j - 1] + c[pos];
            cyc++;
            if (pos == i)
                break;
        }
        ll max_all = *max_element(&w[1], &w[cyc + 1]);
        ll max_mod = *max_element(&w[1], &w[k % cyc + 1]);
        ll t = max_mod;
        if (k >= cyc) {
            chmax(t, (k / cyc) * w[cyc] + (k % cyc == 0 ? 0LL : max(0LL, max_mod)));
            chmax(t, ((k / cyc) - 1) * w[cyc] + max_all);
        }
        chmax(ans, t);
    }

    cout << ans << endl;

    return 0;
}