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

int a[100000];

int main() {
    int n;
    while (cin >> n && n > 0) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int sum = accumulate(a, a + n, 0);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] * n <= sum) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}