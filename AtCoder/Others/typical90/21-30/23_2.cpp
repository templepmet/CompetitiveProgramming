#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int h, w;
vector<int> mask;

bool check(int row, int obj, int upp) {
  if ((row & obj) > 0) return false;
  if ((row & upp) > 0) return false;
  if (((row >> 1) & upp) > 0) return false;
  if ((((row << 1) & ((1 << w) - 1)) & upp) > 0) return false;
  for (int i = 0; i < w - 1; ++i) {
    if ((row & mask[i]) == mask[i]) return false;
  }
  return true;
}

int main() {
  cin >> h >> w;
  if (h > 9 || w > 9) {
    return 0;
  }
  vector<string> fs(h);
  vector<int> f(h);
  for (int i = 0; i < h; ++i) {
    cin >> fs[i];
  }
  for (int i = 0; i < h; ++i) {
    int t = 0, b = 1;
    for (int j = 0; j < w; ++j) {
      if (fs[i][w - j - 1] == '#') {
        t += b;
      }
      b <<= 1;
    }
    f[i] = t;
  }
  if (w > 1) {
  	mask.resize(w - 1);
  	mask[0] = 0b11;
  	for (int i = 0; i < w - 2; ++i) {
      mask[i + 1] = mask[i] << 1;
  	}
  }
  
  vector<vector<ll>> dp(h, vector<ll>(1 << w, 0LL));
  for (int i = 0; i < (1 << w); ++i) {
    if (check(i, f[0], 0)) {
      dp[0][i]++;
    }
  }
  
  for (int i = 1; i < h; ++i) {
    for (int j = 0; j < (1 << w); ++j) { // src loop
      for (int k = 0; k < (1 << w); ++k) { // dst loop
        if (check(k, f[i], j)) {
          (dp[i][k] += dp[i - 1][j]) %= MOD;
        }
      }
    }
  }
  ll ans = accumulate(dp[h - 1].begin(), dp[h - 1].end(), 0LL) % MOD;
  cout << ans << endl;
  
  return 0;
}