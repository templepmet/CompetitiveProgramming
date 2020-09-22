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

int n;
ll a[1000001][4];

int main() {
    cin >> n;
    a[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        (a[i][0] += a[i - 1][0] * 8) %= MOD;
        (a[i][1] += a[i - 1][0]) %= MOD;
        (a[i][1] += a[i - 1][1] * 9) %= MOD;
        (a[i][2] += a[i - 1][0]) %= MOD;
        (a[i][2] += a[i - 1][2] * 9) %= MOD;
        (a[i][3] += a[i - 1][1] + a[i - 1][2]) %= MOD;
        (a[i][3] += a[i - 1][3] * 10) %= MOD;
    }
    cout << a[n][3] << endl;

    return 0;
}