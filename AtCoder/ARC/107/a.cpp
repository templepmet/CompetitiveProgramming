#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 998244353

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    ll ans = 1, t;
    ll a, b, c;
    cin >> a >> b >> c;
    
    t = c * (c + 1) / 2;
    t %= MOD;
    ans *= t;
    ans %= MOD;

    t = b * (b + 1) / 2;
    t %= MOD;
    ans *= t;
    ans %= MOD;
    
    t = a * (a + 1) / 2;
    t %= MOD;
    ans *= t;
    ans %= MOD;

    cout << ans << endl;

    return 0;
}