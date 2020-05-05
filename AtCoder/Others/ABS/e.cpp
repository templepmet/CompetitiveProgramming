#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int a, b, c, x, ans = 0;
    cin >> a >> b >> c >> x;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            for (int k = 0; k <= c; ++k) {
                if (500 * i + 100 * j + 50 * k == x)
                    ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}