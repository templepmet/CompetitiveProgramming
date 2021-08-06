#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> dp(8, 0); // |atcoder| = 7
    string at = "atcoder";
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        int j = at.find(s[i]);
        if (j >= 0 && j < 7) {
            (dp[j + 1] += dp[j]) %= MOD;
        }
    }
    cout << dp[7] << endl;

    return 0;
}