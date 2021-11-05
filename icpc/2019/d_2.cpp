#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int dp[1001][1001];

int main() {
	int n, m;
	
	while (cin >> n >> m && n > 0) {
		vector<int> a(n), b(n), c(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
			c[i] = (b[i] - a[i] + m) % m;
		}
		fill(dp[0], dp[n], INF);
		for (int i = 0; i < n; ++i) {
			dp[0][i] = c[0] + m * i;
		}
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (c[i - 1] < c[i]) {
					chmin(dp[i][j], dp[i - 1][j] + c[i] - c[i - 1]);
					if (j < n - 1) {
						chmin(dp[i][j], dp[i - 1][j + 1]);
					}
				}
				else {
					chmin(dp[i][j], dp[i - 1][j]);
					if (j > 0) {
						chmin(dp[i][j], dp[i - 1][j - 1] + c[i] - c[i - 1] + m);
					}
				}
			}
		}
		cout << *min_element(&dp[n - 1][0], &dp[n - 1][n]) << endl;
	}

	return 0;
}