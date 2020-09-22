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

#define M 1000000

int dp1[M + 1];
int dp2[M + 1];

void pre() {
    fill(dp1, dp1 + M + 1, INF);
    fill(dp2, dp2 + M + 1, INF);
    dp1[0] = 0;
    dp2[0] = 0;
    for (int i = 1; ; ++i) {
        int k = i * (i + 1) * (i + 2) / 6;
        if (k > M)
            break;
        for (int j = 0; j <= M - k; ++j) {
            chmin(dp1[j + k], dp1[j] + 1);
            if (k % 2)
                chmin(dp2[j + k], dp2[j] + 1);
        }
    }
}

int main() {
    pre();
    int n;
    while (cin >> n && n > 0) {
        cout << dp1[n] << " " << dp2[n] << endl;
    }

    return 0;
}