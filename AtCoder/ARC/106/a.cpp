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
    ll n, p = 1;
    cin >> n;
    for (int a = 1; ; ++a) {
        if (p > n / 3) {
            break;
        }
        p *= 3;
        ll q = n - p;
        int b = 0;
        while (q > 1) {
            b++;
            if (q % 5 != 0) {
                break;
            }
            q /= 5;
        }
        if (q == 1 && b > 0) {
            cout << a << " " << b << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}