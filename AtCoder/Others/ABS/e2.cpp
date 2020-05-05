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
            int k = x - 500 * i - 100 * j;
            if (k >= 0 && k <= 50 * c && k % 50 == 0)
                ans++;
        }
    }
    cout << ans << endl;

    return 0;
}