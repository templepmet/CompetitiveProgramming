#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int n, h;
    ll t, a[40];
    cin >> n >> t;
    h = n / 2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(1 << h);
    for (int k = 0; k < (1 << h); ++k) {
        ll sum = 0;
        for (int i = 0; i < h; ++i) {
            if ((k >> i) & 1) {
                sum += a[i];
            }
        }
        b[k] = sum;
    }
    sort(b.begin(), b.end());
    ll ans = 0;
    for (int k = 0; k < (1 << (n - h)); ++k) {
        ll sum = 0;
        for (int i = 0; i < n - h; ++i) {
            if ((k >> i) & 1) {
                sum += a[i + h];
            }
        }
        if (t - sum < 0)
            continue;
        ll p = sum + *(--upper_bound(b.begin(), b.end(), t - sum));
        ans = max(ans, p);
    }
    cout << ans << endl;

    return 0;
}