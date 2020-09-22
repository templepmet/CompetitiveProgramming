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
    int c[3][3], a[3][3], b[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> c[i][j];
        }
    }

    bool f;
    rep(i, 101) {
        rep(j, 101) {
            rep(k, 101) {
                f = true;
                for (int l = 0; l < 3; ++l) {
                    b[0][l] = c[0][l] - i;
                    b[1][l] = c[1][l] - j;
                    b[2][l] = c[2][l] - k;
                    if (b[0][l] < 0 || b[0][l] > 100)
                        f = false;
                    if (b[1][l] != b[0][l] || b[2][l] != b[0][l])
                        f = false;
                }
                if (f) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}