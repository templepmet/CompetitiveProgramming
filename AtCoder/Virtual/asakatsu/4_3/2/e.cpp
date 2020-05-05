#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, c, d[30][30], cc[500][500], dd[3][30] = { 0 };
    cin >> n >> c;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> d[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cc[i][j];
            cc[i][j]--;
        }
    }

    for (int k = 0; k < c; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dd[(i + j) % 3][k] += d[cc[i][j]][k];
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < c; ++i) { // mod 0
        for (int j = 0; j < c; ++j) { // mod 1
            if (i == j)
                continue;
            for (int k = 0; k < c; ++k) { // mod 2
                if (k == i || k == j)
                    continue;
                ans = min(ans, dd[0][i] + dd[1][j] + dd[2][k]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}