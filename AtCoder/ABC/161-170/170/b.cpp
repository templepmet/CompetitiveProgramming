#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> void chmax(T& a, T b){ if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b){ if (a > b) { a = b; } }

int main() {
    int x, y;
    cin >> x >> y;
    int a = 2 * x - y / 2;
    int b = y / 2 - x;
    if (y % 2 || a < 0 || b < 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    return 0;
}