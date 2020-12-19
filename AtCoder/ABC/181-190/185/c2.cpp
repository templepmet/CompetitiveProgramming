#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

ll dp[201][13];

ll dfs(int l, int n) {
    if (dp[l][n] >= 0) {
        return dp[l][n];
    }
    if (l < n) {
        return dp[l][n] = 0;
    }
    if (l == n || n == 1) {
        return dp[l][n] = 1;
    }
    ll sum = 0;
    for (int i = 1; i < l; ++i) {
        sum += dfs(l - i, n - 1);
    }
    return dp[l][n] = sum;
}

int main() {
    int l;
    cin >> l;
    fill(dp[0], dp[201], -1);
    cout << dfs(l, 12) << endl;

    return 0;
}