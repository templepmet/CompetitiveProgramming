#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

ll a[200010];
ll b[200010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n, greater<ll>());
    for (int i = 0; i < n; ++i) {
        b[i + 1] = b[i] + a[n - i - 1];
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += a[i] * (n - i - 1);
        ans -= b[n - i - 1];
    }
    cout << ans << endl;

    return 0;
}