#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

ll n, a[300000];

int main() {
    cin >> n;
    for (int i = 0; i < n * 3; ++i)
        cin >> a[i];
    sort(a, a + n * 3, greater<ll>());
    
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i * 2 + 1];
    }
    cout << ans << endl;

    return 0;
}