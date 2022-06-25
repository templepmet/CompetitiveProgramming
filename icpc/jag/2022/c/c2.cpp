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
		int m = base.size();
		for (int i = 0; i < m; ++i) {
			for (int num = l - 2; num >= 1; --num) {
				for (int st = 1; st + num < l; ++st) {
					bool isallok = true;
					for (int j = 0; j < m; ++j) {
						if (i == j) continue;
						bool flag = true;
						for (int h = 0; h < l; ++h) {
							if (h >= st && h < st + num) continue;
							if (base[i][h] != base[j][h]) flag = false;
						}
						if (flag) {
							isallok = false;
							break;
						}
					}
					if (isallok) {
						// cout << base[i] << " " << st << " " << num << endl;
						ans += num;
						num = 0;
						break;
					}
				}
			}
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
