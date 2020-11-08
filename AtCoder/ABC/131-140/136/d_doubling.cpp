#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[18][100000];
int ans[100000];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R')
            dp[0][i] = i + 1;
        else
            dp[0][i] = i - 1;
    }
    for (int i = 0; i < 17; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i + 1][j] = dp[i][dp[i][j]];
        }
    }
    for (int i = 0; i < n; ++i) {
        ans[dp[17][i]]++;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}