#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, m, ans = 0;
    int k[10], s[10][10], p[10];
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> k[i];
        for (int j = 0; j < k[i]; ++j) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < (1 << n); ++i) {
        bool f = true;
        for (int j = 0; j < m; ++j) {
            int cnt = 0;
            for (int l = 0; l < k[j]; ++l) {
                if ((i & (1 << (s[j][l] - 1))) > 0)
                    cnt++;
            }
            if (cnt % 2 != p[j])
                f = false;
        }
        if (f) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}