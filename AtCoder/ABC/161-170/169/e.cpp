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

int a[200000], b[200000];

int main() {
    int n, c, d;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    if (n % 2) {
        c = a[n / 2];
        d = b[n / 2];
    }
    else {
        c = a[n / 2 - 1] + a[n / 2];
        d = b[n / 2 - 1] + b[n / 2];
    }
    cout << d - c + 1 << endl;

    return 0;
}