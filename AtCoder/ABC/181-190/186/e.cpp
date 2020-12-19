#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

template<class T>
T gcd(T a, T b){return b ? gcd(b, a % b) : a;}
template<class T>
T lcm(T a, T b){return a / gcd(a, b) * b;}

int main() {
    int t;
    ll n, s, k;
    cin >> t;
    while (t--) {
        cin >> n >> s >> k;
        ll p, q, d = gcd(n, k);
        if (s % d != 0) {
            cout << -1 << endl;
            continue;
        }
        ll c = s / d;
        ll a = n / d;
        ll b = k / d;
        ext_gcd(a, b, p, q);
        q *= c;
        if (q > 0) {
            cout << -(q - (q / a + 1) * a) << endl;
        }
        else {
            cout << -(q + ((-q) / a) * a) << endl;
        }
    }

    return 0;
}