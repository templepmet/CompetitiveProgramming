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

int main() {
    int n;
    ll a = 0, x, ans = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (i > 0)
            ans += max(0LL, a - x);
        a += max(0LL, x - a);
    }
    cout << ans << endl;

    return 0;
}