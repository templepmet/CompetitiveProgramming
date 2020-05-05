#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[16][16];
int b[16][16];
int c[16];
int ans = 0;

void dfs(int d) {
    if (d > n) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (c[i]) { // 1:正直
                for (int j = 1; j <= n; ++j) {
                    if (b[i][j]) {
                        if (a[i][j] != c[j])
                            return;
                    }
                }
                cnt++;
            }
            else {
                for (int j = 1; j <= n; ++j) {
                    if (b[i][j]) {
                        if (a[i][j] == c[j])
                            return;
                    }
                }
            }
        }
        ans = max(ans, cnt);
        return;
    }
    dfs(d + 1);
    c[d] = 1;
    dfs(d + 1);
    c[d] = 0;
}

int main() {
    cin >> n;
    int k, x, y;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        while (k--) {
            cin >> x >> y;
            a[i][x] = y;
            b[i][x] = 1;
        }
    }
    dfs(1);
    cout << ans << endl;

    return 0;
}