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
    ll x, k, d, ans;
    cin >> x >> k >> d;
    x = abs(x);
    if (x / d < k) {
        if ((k - (x - x % d) / d) % 2 == 0)
            ans = x % d;
        else
            ans = d - x % d;
    }
    else {
        ans = x - k * d;
    }
    cout << ans << endl;

    return 0;
}