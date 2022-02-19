#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
	string s, t;
	cin >> s >> t;
	int sl = s.size();
	int tl = t.size();
	vector<vector<int>> dp(sl + 1, vector<int>(tl + 1, 0));
	for (int i = 0; i < sl; ++i) {
		for (int j = 0; j < tl; ++j) {
			chmax(dp[i + 1][j + 1], max({dp[i][j] + (s[i] != t[j]), dp[i][j + 1], dp[i + 1][j]}));
		}
	}
	cout << dp[sl][tl] << endl;

	return 0;
}