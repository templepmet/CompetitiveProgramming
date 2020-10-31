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

ll n, k, ans = 0;

ll f(ll a) {
    if (a < 2 || a > 2 * n)
        return 0;
    if (a > n + 1)
        a = n + 1 - (a - (n + 1));
    return a - 1;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= 2 * n; ++i) {
        ans += f(i) * f(i - k);
    }
    cout << ans << endl;

    return 0;
}