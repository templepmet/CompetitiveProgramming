#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    ll a, b, v, x, ans = 0;
    cin >> a >> b >> x;
    for (int d = 1; d <= 10; ++d) {
        v = min(min((x - b * d) / a, (ll)1e9), (ll)pow(10LL, d) - 1);
        if ((int)log10(v) + 1 == d)
            ans = max(ans, v);
    }
    cout << ans << endl;

    return 0;
}