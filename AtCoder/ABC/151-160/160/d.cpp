#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int d[2000] = { 0 };
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            d[min(j - i, abs(x - i) + abs(j - y) + 1)]++;
        }
    }
    for (int i = 1; i < n; ++i) {
        cout << d[i] << endl;
    }

    return 0;
}