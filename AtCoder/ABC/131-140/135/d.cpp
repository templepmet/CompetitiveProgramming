#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

using ll = long long;

int dp[100001][13];

int main() {
    string s;
    cin >> s;
    int n =s.size();
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] =='?') {
            for (int j = 0; j < 13; ++j) {
                for (int k = 0; k < 10; ++k) {
                    (dp[i + 1][((j * 10) + k) % 13] += dp[i][j]) %= MOD;
                }
            }
        }
        else {
            for (int j = 0; j < 13; ++j) {
                (dp[i + 1][((j * 10) + (s[i] - '0')) % 13] += dp[i][j]) %= MOD;
            }
        }
    }
    cout << dp[n][5] << endl;

    return 0;
}