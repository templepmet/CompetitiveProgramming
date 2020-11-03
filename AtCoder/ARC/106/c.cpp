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
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 0) {
        cout << 114514 << " " << 1919810 << endl;
        return 0;
    }
    if (m < 0 || n < m + 2) {
        cout << -1 << endl;
        return 0;
    }
    int t = 2, c;
    for (int i = 0; i < m; ++i) {
        cout << t++ << " ";
        cout << t++ << endl;
    }
    c = t + 1;
    for (int i = 0; i < n - (m + 2); ++i) {
        cout << c++ << " " << (int)(1e9 - i) << endl;
    }
    cout << t << " " << c++ << endl;
    cout << 1 << " " << c << endl;

    return 0;
}