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

int n, w[300];
int v[300][300];

bool check(int a, int b) {
    if (a < 0 || b >= n)
        return false;
    if (abs(w[a] - w[b]) > 1)
        return false;
    return true;
}

void dfs(int a, int b) {
    if (v[a][b])
        return;
    v[a][b] = 1;
    if (check(a - 1, b + 1))
        dfs(a - 1, b + 1);
    if (check(b + 1, b + 2))
        dfs(a, b + 2);
    if (check(a - 2, a - 1))
        dfs(a - 2, b);
}

int main() {
    while (cin >> n && n > 0) {
        rep(i, n) cin >> w[i];
        fill(v[0], v[n], 0);
        rep(i, n - 1) {
            if (check(i, i + 1))
                dfs(i, i + 1);
        }
        int ans = 0;
        rep(i, n) {
            rep (j, n) {
                if (v[i][j])
                    chmax(ans, j - i + 1);
            }
        }
        cout << ans << endl;
    }

    return 0;
}

// たたいた部分と接していなくてもたたいてOK