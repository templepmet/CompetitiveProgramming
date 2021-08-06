#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

vector<vector<ll>> mul(vector<vector<ll>> &a, vector<vector<ll>> &b) {
    int n = a.size();
    int m = a[0].size();
    int m2 = b.size();
    int l = b[0].size();
    assert(m == m2);
    vector<vector<ll>> c(n, vector<ll>(l));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            ll sum = 0;
            for (int k = 0; k < m; ++k) {
                sum += (a[i][k] * b[k][j]) % MOD;
                sum %= MOD;
            }
            c[i][j] = sum;
        }
    }
    return c;
}

int main() {
    ll n;
    int b, k;
    cin >> n >> b >> k;
    if (b > 30) {
        return 0;
    }

    vector<int> c(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
    }
    vector<vector<ll>> dp(b, vector<ll>(1, 0));
    vector<vector<ll>> m(b, vector<ll>(b, 0));
    dp[0][0] = 1;
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < k; ++j) {
            m[(i * 10 + c[j]) % b][i] += 1;
        }
    }

    for (int i = 0; i < 63; ++i) {
        if (n & (1LL << i)) {
            dp = mul(m, dp);
        }
        m = mul(m, m);
    }
    cout << dp[0][0] << endl;

    return 0;
}

// O(B^3 logN)