#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, x[8], y[8], p[8];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        p[i] = i;
    }

    double sum = 0, d;
    int cnt = 0;
    do {
        d = 0;
        for (int i = 0; i < n - 1; ++i) {
            d += sqrt(pow(x[p[i]] - x[p[i + 1]], 2) + pow(y[p[i]] - y[p[i + 1]], 2));
        }
        sum += d;
        cnt++;
    } while (next_permutation(p, p + n));

    cout << fixed << setprecision(10);
    cout << sum / cnt << endl;

    return 0;
}