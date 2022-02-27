#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

// O(hw2^w)
// 289 * 1.25 1e5

int main() {
	int h, w;
	cin >> h >> w;
	if (h > 17 || w > 17) return 0;
	vector<string> fs(h);
	for (int i = 0; i < h; ++i) {
		cin >> fs[i];
	}
	// vector<int> f(h);
  // for (int i = 0; i < h; ++i) {
  //   int t = 0, b = 1;
  //   for (int j = 0; j < w; ++j) {
  //     if (fs[i][w - j - 1] == '#') {
  //       t += b;
  //     }
  //     b <<= 1;
  //   }
  //   f[i] = t;
  // }
	vector<vector<ll>> dp(h * w + 1, vector<ll>(1 << (w + 1), 0LL));
	dp[0][0] = 1;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			int p = i * w + j;
			for (int k = 0; k < (1 << (w + 1)); ++k) {
				(dp[p + 1][k >> 1] += dp[p][k]) %= MOD; // 置かない
				if (fs[i][j] == '.') {
					ll mask = 0b10;
					if (j > 0) {
						mask |= ((1 << w) | 0b1);
					}
					if (j < w - 1) {
						mask |= 0b100;
					}
					if ((k & mask) == 0) {
						(dp[p + 1][(k >> 1) + (1 << w)] += dp[p][k]) %= MOD; // 置く
					}
				}
			}
		}
	}
	ll ans = accumulate(dp[h * w].begin(), dp[h * w].end(), 0LL) % MOD;
	cout << ans << endl;

	return 0;
}