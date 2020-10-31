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

template<class T>
T gcd(T a, T b){return b ? gcd(b, a % b) : a;}

template<class T>
T lcm(T a, T b){return a / gcd(a, b) * b;}
ll powMod(ll a, ll b, ll p) {
    if (b == 0) return 1;
    if (b % 2) return (a * powMod(a, b - 1, p)) % p;
    return powMod(a * a % p, b / 2, p);
}
int main() {
    for (int i = 1; i <= 72; ++i) {
        if (gcd(72, i) == 1) {
            cout << i << " ";
        }
    }

    cout << endl << powMod(7, 29, 95) << endl;
    cout << powMod(87, 5, 95) << endl;

    return 0;
}