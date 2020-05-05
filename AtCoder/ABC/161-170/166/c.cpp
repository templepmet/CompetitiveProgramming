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

int n, m, h[100001], c[100001];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        if (h[a] < h[b])
            c[a] = 1;
        if (h[a] > h[b])
            c[b] = 1;
        if (h[a] == h[b]) {
            c[a] = 1;
            c[b] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (c[i] == 0)
            ans++;
    }
    cout << ans << endl;

    return 0;
}