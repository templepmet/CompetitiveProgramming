#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    ll n;
    int ans = INF;
    cin >> n;
    for (ll i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            ans = min(ans, max((int)log10(i) + 1, (int)log10(n / i) + 1));
        }
    }
    cout << ans << endl;

    return 0;
}