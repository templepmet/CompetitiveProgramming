#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define BIAS 100

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    ll p;
    while (cin >> p && p > 0) {
        ll ans = 1e18, t;
        for (ll i = 1; i * i <= p; ++i) {
            if (p % i != 0) continue;
            t = p / i;
            for (ll j = 1; j * j <= t; ++j) {
                if (t % j != 0) continue;
                chmin(ans, i + j + p / i / j);
            }
        }
        cout << ans << endl;
    }

    return 0;
}