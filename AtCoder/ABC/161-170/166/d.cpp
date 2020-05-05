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

ll x;

void f(ll c) {
    for (ll b = -1e4; b <= 1e4; ++b) {
        ll a = b + c;
        if (pow(a, 5LL) - pow(b, 5LL) == x) {
            cout << a << " " << b << endl;
            exit(0);
        }
    }
}

int main() {
    cin >> x;
    for (ll i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            f(i);
            if (x / i != i)
                f(x / i);
        }
    }

    return 0;
}