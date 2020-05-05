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
    int n, k, d, a, b[101] = { 0 };
    cin >> n >> k;
    while (k--) {
        cin >> d;
        for (int i = 0; i < d; ++i) {
            cin >> a;
            b[a] = 1;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (b[i] == 0)
            cnt++;
    }
    cout << cnt << endl;

    return 0;
}