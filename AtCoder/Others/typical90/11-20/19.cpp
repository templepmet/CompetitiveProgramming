#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int n;
int a[400];
int dp[400][400];

int dfs(int l, int r) {
	if (dp[l][r] < INF) {
		return dp[l][r];
	}
	if (l >= r) {
		return dp[l][r] = 0;
	}
	int cost = INF;
	chmin(cost, dfs(l + 1, r - 1) + abs(a[l] - a[r]));
	for (int i = l + 1; i <= r - 2; i += 2) {
		chmin(cost, dfs(l, i) + dfs(i + 1, r));
	}
	return dp[l][r] = cost;
}

int main() {
	cin >> n;
	fill(dp[0], dp[n * 2], INF);
	for (int i = 0; i < n * 2; ++i) {
		cin >> a[i];
	}
	cout << dfs(0, n * 2 - 1) << endl;

	return 0;
}