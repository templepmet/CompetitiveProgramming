#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

ll dp[201][13];

ll f(int l, int n) {
    if (dp[l][n] >= 0)
        return dp[l][n];
    if (n == 1) {
        return dp[l][n] = 1;
    }
    if (l < n) {
        return dp[l][n] = 0;
    }
    ll sum = 0;
    for (int i = 1; i <= l - 1; ++i) {
        for (int j = 1; j <= n - 1; ++j) {
            sum += f(i, j) * f(l - i, n - j);
        }
    }
    return dp[l][n] = sum;
}

int main() {
    int l;
    cin >> l;
    fill(dp[0], dp[201], -1);
    cout << f(l, 12) << endl;

    return 0;
}