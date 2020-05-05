#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, y;
    cin >> n >> y;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n - i; ++j) {
            int k = n - j - i;
            if (10000 * i + 5000 * j + 1000 * k == y) {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;

    return 0;
}