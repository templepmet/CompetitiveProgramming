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

int main() {
    ll n;
    int b, k, c;
    cin >> n >> b >> k;

    vector<vector<ll>> dp(64, vector<ll>(b, 0));
    vector<ll> v(b, 0), tmp(b, 0);
    v[0] = 1;
    for (int i = 0; i < k; ++i) {
        cin >> c;
        dp[0][c % b] += 1;
    }
    for (int i = 0; i < 63; ++i) {
        ll t = pow_mod(10, pow(2, i), b);
        for (int j = 0; j < b; ++j) {
            for (int l = 0; l < b; ++l) {
                (dp[i + 1][(j * t + l) % b] += (dp[i][j] * dp[i][l]) % MOD) %= MOD;
            }
        }
    }
    for (int i = 0; i < 63; ++i) {
        if (n & (1LL << i)) {
            ll t = pow_mod(10, pow(2, i), b);
            fill(tmp.begin(), tmp.end(), 0);
            for (int j = 0; j < b; ++j) {
                for (int l = 0; l < b; ++l) {
                    (tmp[(j * t + l) % b] += (v[j] * dp[i][l]) % MOD) %= MOD;
                }
            }
            v = tmp;
        }
    }
    cout << v[0] << endl;

    return 0;
}

// O(NBK)