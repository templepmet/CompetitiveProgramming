#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

const int MAXLEN = 30;

void solve(int n) {
	string s;
	vector<vector<string>> ss(MAXLEN + 1);
	for (int i = 0; i < n; ++i) {
		cin >> s;
		ss[s.size()].push_back(s);
	}
	int ans = 0;
	for (int l = 0; l <= MAXLEN; ++l) {
		vector<string> base = ss[l];
		vector<string> dict = ss[l];
		int m = base.size();
		for (int i = 0; i < m; ++i) {
			for (int j = i + 1; j < m; ++j) {
				if (base[i][0] != base[j][0] || base[i][l - 1] != base[j][l - 1]) {
					continue;
				}
				for (int k = 0; k < l; ++k) {
					if (base[i][k] == base[j][k]) {
						dict[i][k] = '.';
						dict[j][k] = '.';
					}
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			int num = 0;
			for (int k = 0; k < l; ++k) {
				if (dict[i][k] != '.') {
					chmax(num, l - (k + 1) - 1);
					break;
				}
			}
			for (int k = l - 1; k >= 0; --k) {
				if (dict[i][k] != '.') {
					chmax(num, k - 1);
					break;
				}
			}
			cout << dict[i] << " " << num << endl;
			ans += num;
		}
	}
	cout << ans << endl;
}

int main() {
	int n;
	while (cin >> n && n > 0) {
		solve(n);
	}

	return 0;
}