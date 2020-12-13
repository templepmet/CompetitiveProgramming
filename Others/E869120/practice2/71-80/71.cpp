#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

ll pow_mod(ll a, ll b, ll p) {
    if (b == 0) return 1;
    if (b % 2) return (a * pow_mod(a, b - 1, p)) % p;
    return pow_mod(a * a % p, b / 2, p);
}

int a[120000];
int c[120002];
int b[120000];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0) {
            b[i] = pow_mod(a[i - 1], a[i], MOD);
        }
    }
    c[0] = 1;
    for (int i = 1; i <= q; ++i) {
        cin >> c[i];
    }
    c[q + 1] = 1;
    for (int i = 1; i < n; ++i) {
        (b[i] += b[i - 1]) %= MOD;
    }

    int ans = 0;
    for (int i = 0; i <= q; ++i) {
        int r = max(c[i], c[i + 1]);
        int l = min(c[i], c[i + 1]);
        (ans += (b[r - 1] - b[l - 1] + MOD) % MOD) %= MOD;
    }
    cout << ans << endl;

    return 0;
}