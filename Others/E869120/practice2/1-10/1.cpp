#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, x;
    while (cin >> n >> x && n > 0) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int t = x - i - j;
                if (j < t && t <= n) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}