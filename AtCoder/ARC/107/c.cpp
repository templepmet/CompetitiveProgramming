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
    int n, k, a[50][50];
    ll t;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int c1, c2;
    int b1[50][50] = {}, b2[50][50] = {};
    ll t1 = 0, t2 = 0;
    for (int x = 0; x < n; ++x) {
        c1 = 0;
        c2 = 0;
        for (int y = x + 1; y < n; ++y) {
            bool f = true;
            for (int i = 0; i < n; ++i) {
                if (a[i][x] + a[i][y] > k) {
                    f = false;
                } 
            }
            if (f) {
                b1[x][y] = 1;
                c1++;
            }

            f = true;
            for (int j = 0; j < n; ++j) {
                if (a[x][j] + a[y][j] > k) {
                    f = false;
                }
            }
            if (f) {
                b2[x][y] = 1;
                c2++;
            }
        }
        ll tmp = 1;
        for (int i = 1; i <= c1 + 1; ++i) {
            tmp *= i;
            tmp %= MOD;
        }
        if (tmp > 1) {
        t1 += tmp;
        t1 %= MOD;
        }
        tmp = 1;
        for (int i = 1; i <= c2 + 1; ++i) {
            tmp *= i;
            tmp %= MOD;
        }
        if (tmp > 1) {
        t2 += tmp;
        t2 %= MOD;
        }
    }
    cout << endl;

    rep(i, n) {
        rep(j, n) {
            cout << b1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    rep(i, n) {
        rep(j, n) {
            cout << b2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << (t1 * t2) % MOD << endl;

    return 0;
}