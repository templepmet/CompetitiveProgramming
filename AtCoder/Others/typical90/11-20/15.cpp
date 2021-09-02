#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

ll pow_mod(ll a, ll b, ll p) {
    if (b == 0) return 1;
    if (b % 2) return (a * pow_mod(a, b - 1, p)) % p;
    return pow_mod(a * a % p, b / 2, p);
}

ll inv_mod(ll a, ll p) {
    return pow_mod(a, p - 2, p);
}

int n;
ll ans[100001];
ll mulb[100001];
ll invb[100001];

void pre() {
    mulb[0] = 1;
    invb[0] = 1;
    for (int i = 1; i <= n; ++i) {
        (mulb[i] = mulb[i - 1] * i) %= MOD;
        (invb[i] = invb[i - 1] * inv_mod(i, MOD)) %= MOD;
    }
}

ll combi(ll n, ll r) {
    ll t = mulb[n];
    (t *= invb[n - r]) %= MOD;
    (t *= invb[r]) %= MOD;
    return t;
}

int main() {
    cin >> n;
    pre();

    for (int a = 1; a <= n; ++a) {
        for (int k = 1; k <= n; ++k) {
            if (n - (k - 1) * (a - 1) < a) {
                break;
            }
            (ans[k] += combi(n - (k - 1) * (a - 1), a)) %= MOD;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i + 1] << endl;
    }

    return 0;
}