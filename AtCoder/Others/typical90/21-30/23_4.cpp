#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int b2i[1 << 25];

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> fs(h);
	for (int i = 0; i < h; ++i) {
		cin >> fs[i];
	}
	vector<int> m(w), m2(w);
	for (int i = 0; i < w; ++i) {
		m[i] = 0b11 << i;
	}
	m2[0] = 0b100;
	for (int i = 1; i < w; ++i) {
		m2[i] = 0b1001 << (i - 1);
	}
	fill(b2i, b2i + (1 << (w + 1)), -1);
	for (int t = 0; t < (1 << (w + 1)); ++t) {
		bool f = true;
		for (int i = 0; i < w; ++i) {
			if ((t & m[i]) == m[i]) {
				f = false;
				break;
			}
		}
		if ((t & 1) & (t >> w)) {
			f = false;
		}
		if (f) {
			b2i[t] = 1;
			for (int i = 0; i < w; ++i) {
				if ((t & m2[i]) == 0) {
					int u = t | m[i];
					if (((u & 1) & (u >> w)) == 0) {
						b2i[u] = 1;
					}
				}
			}
		}
	}

	int num = 0;
	for (int i = 0; i < (1 << (w + 1)); ++i) {
		if (b2i[i] >= 0) {
			b2i[i] = num++;
		}
	}
	vector<int> i2b(num);
	for (int i = 0, j = 0; i < (1 << (w + 1)); ++i) {
		if (b2i[i] >= 0) {
			i2b[j++] = i;
		}
	}
	// cout << num << endl;

	vector<vector<int>> dp(h * w + 1, vector<int>(num, 0LL));
	dp[0][0] = 1;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			int p = i * w + j;
			for (int k = 0; k < num; ++k) {
				if (b2i[i2b[k] >> 1] >= 0) {
					(dp[p + 1][b2i[i2b[k] >> 1]] += dp[p][k]) %= MOD; // 置かない
				}
				if (fs[i][j] == '.') {
					ll mask = 0b10;
					if (j > 0) {
						mask |= ((1 << w) | 0b1);
					}
					if (j < w - 1) {
						mask |= 0b100;
					}
					if ((i2b[k] & mask) == 0) {
						if (b2i[(i2b[k] >> 1) + (1 << w)] >= 0) {
							(dp[p + 1][b2i[(i2b[k] >> 1) + (1 << w)]] += dp[p][k]) %= MOD; // 置く
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < num; ++i) {
		(ans += dp[h * w][i]) %= MOD;
	}
	cout << ans << endl;

	return 0;
}