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
    int n, x, y;
    int pmax = 0, pmin = 2e9, mmax = -2e9, mmin = 2e9;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        chmax(pmax, x + y);
        chmin(pmin, x + y);
        chmax(mmax, x - y);
        chmin(mmin, x - y);
    }
    cout << max(pmax - pmin, mmax - mmin) << endl;

    return 0;
}