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

int n;
ll h[100000], s[100000];
int t[100000];

bool isok(ll p) {
    fill(t, t + n, 0);
    for (int i = 0; i < n; ++i) {
        if (p < h[i])
            return false;
        t[(int)min((ll)(n - 1), (p - h[i]) / s[i])]++;
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0)
            t[i] += t[i - 1];
        if (i + 1 < t[i])
            return false;
    }
    return true;
}

int main() {
    cin >> n;
    rep(i, n) {
        cin >> h[i] >> s[i];
    }
    ll l = 0, r = 1e18, m; // rは常に条件を満たす
    while (r - l > 1) {
        m = (l + r) / 2;
        if (isok(m))
            r = m;
        else
            l = m;
    }
    cout << r << endl;

    return 0;
}