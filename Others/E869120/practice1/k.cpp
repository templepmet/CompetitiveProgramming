#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, a[15], x[15][15], y[15][15];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < a[i]; ++j) {
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        int cnt = 0;
        bool f = true;
        for (int j = 0; j < n; ++j) {
            if (((1 << j) & i) == 0)
                continue;
            cnt++;
            for (int k = 0; k < a[j]; ++k) {
                if (((i >> x[j][k]) & 1) != y[j][k])
                    f = false;
            }
        }
        if (f) {
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;

    return 0;
}