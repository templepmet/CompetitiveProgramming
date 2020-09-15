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
    int s;
    ll a[2001] = {};
    cin >> s;
    a[0] = 1;
    for (int i = 0; i < s; ++i) {
        for (int j = 3; j <= s - i; ++j) {
            a[i + j] += a[i];
            a[i + j] %= MOD;
        }
    }
    cout << a[s] << endl;

    return 0;
}