#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    ll n;
    int b, k;
    cin >> n >> b >> k;
    if (n > 10000) {
        return 0;
    }

    vector<int> c(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(b, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < b; ++j) {
            for (int l = 0; l < k; ++l) {
                (dp[i + 1][(j * 10 + c[l]) % b] += dp[i][j]) %= MOD;
            }
        }
    }
    cout << dp[n][0] << endl;

    return 0;
}

// O(NBK)