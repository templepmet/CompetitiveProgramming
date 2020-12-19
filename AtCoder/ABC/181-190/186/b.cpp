#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int h, w, a[100][100], t = INF;
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
            t = min(t, a[i][j]);
        }
    }
    int ans = INF;
    for (int k = 0; k <= t; ++k) {
        int sum = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                sum += a[i][j] - k;
            }
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;

    return 0;
}