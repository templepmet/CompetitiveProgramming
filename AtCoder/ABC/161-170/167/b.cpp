#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> void chmax(T& a, T b){ a>b?:a=b; }
template<class T> void chmin(T& a, T b){ a<b?:a=b; }

int main() {
    int a, b, c, k, ans = 0;
    cin >> a >> b >> c >> k;
    if (k <= a) {
        cout << k << endl;
    }
    else if (a < k && k <= a + b) {
        cout << a << endl;
    }
    else if (a + b < k && k <= a + b + c) {
        cout << a - (k - (a + b)) << endl;
    }

    return 0;
}