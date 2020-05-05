#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, m, a[100][100];
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            ll sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += max(a[k][i], a[k][j]);
            }
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;

    return 0;
}