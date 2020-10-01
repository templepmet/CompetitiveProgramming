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

int a[30000];

int main() {
    int n, c;
    cin >> n;
    fill(a, a + n, INF);
    rep(i, n) {
        cin >> c;
        a[lower_bound(a, a + n, c) - a] = c;
    }
    int lis = lower_bound(a, a + n, INF) - a;
    cout << n - lis << endl;

    return 0;
}