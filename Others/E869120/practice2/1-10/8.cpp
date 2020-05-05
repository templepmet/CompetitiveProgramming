#include <bits/stdc++.h>

using namespace std;

#define INF (1LL << 62)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n;
    ll a[30], b[30], c[60];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        c[i * 2] = a[i];
        c[i * 2 + 1] = b[i];
    }

    ll ans = INF;
    for (int i = 0; i < n * 2; ++i) {
        for (int j = 0; j < n * 2; ++j) {
            ll sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += abs(a[k] - b[k]) + min(abs(c[i] - a[k]) + abs(c[j] - b[k]), abs(c[i] - b[k]) + abs(c[j] - a[k]));
            }
            ans = min(ans, sum);
        }
    }
    cout << ans << endl;

    return 0;
}