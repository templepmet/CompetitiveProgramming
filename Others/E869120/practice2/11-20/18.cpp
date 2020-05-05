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

int main() {
    int n, q, t, ans = 0;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    cin >> q;
    while (q--) {
        cin >> t;
        int l = -1, r = n, m;
        while (r - l > 1) {
            m = (l + r) / 2;
            if (a[m] < t)
                l = m;
            else
                r = m;
        }
        if (a[r] == t)
            ans++;
    }
    cout << ans << endl;

    return 0;
}