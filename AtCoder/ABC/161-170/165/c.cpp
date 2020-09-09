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

int n, m, q, ans;
int a[50], b[50], c[50], d[50];
int v[11];

void eval() {
    int sum = 0;
    for (int i = 0; i < q; ++i) {
        if (v[b[i]] - v[a[i]] == c[i]) {
            sum += d[i];
        }
    }
    chmax(ans, sum);
}

void dfs(int i) {
    if (i > n) {
        eval();
        return;
    }
    for (int j = v[i - 1]; j <= m; ++j) {
        v[i] = j;
        dfs(i + 1);
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    v[0] = 1;
    dfs(1);

    cout << ans << endl;

    return 0;
}