#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int f[1001][1001];

int main() {
	int n;
	int lx, ly, rx, ry;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> lx >> ly >> rx >> ry;
		f[ly][lx]++;
		f[ly][rx]--;
		f[ry][lx]--;
		f[ry][rx]++;
	}
	for (int i = 0; i < 1001; ++i) {
		for (int j = 1; j < 1001; ++j) {
			f[i][j] += f[i][j - 1];
		}
	}
	for (int i = 1; i < 1001; ++i) {
		for (int j = 0; j < 1001; ++j) {
			f[i][j] += f[i - 1][j];
		}
	}
	vector<int> ans(n + 1);
	for (int i = 0; i < 1001; ++i) {
		for (int j = 0; j < 1001; ++j) {
			ans[f[i][j]]++;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i + 1] << endl;
	}

	return 0;
}