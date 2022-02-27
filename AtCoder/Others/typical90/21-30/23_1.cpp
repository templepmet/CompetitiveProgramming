#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int h, w;

int check(vector<string> &f) {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (f[i][j] == 'o') {
        for (int k = 0; k < 8; ++k) {
          int nx = j + dx[k];
          int ny = i + dy[k];
          if (nx < 0 || ny < 0 || nx >= w || ny >= h) {
			continue;
          }
          if (f[ny][nx] == 'o') {
            return 0;
          }
        }
      }
    }
  }
  return 1;
}

int main() {
  cin >> h >> w;
  if (h > 4 || w > 4) {
    return 0;
  }
  vector<string> f(h);
  for (int i = 0; i < h; ++i) {
    cin >> f[i];
  }
  int l = h * w;
  int ans = 0;
  for (int t = 0; t < (1 << l); ++t) {
    bool flag = true;
    for (int i = 0; i < l; ++i) {
      if (t & (1 << i)) {
        if (f[i / w][i % w] == '#') {
          flag = false;
        }
      }
    }
    if (!flag) {
      continue;
    }
    for (int i = 0; i < l; ++i) {
      if (t & (1 << i)) {
        f[i / w][i % w] = 'o';
      }
    }
    ans += check(f);
    for (int i = 0; i < l; ++i) {
      if (t & (1 << i)) {
        f[i / w][i % w] = '.';
      }
    }
  }
  cout << ans << endl;
  
  return 0;
}