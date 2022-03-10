#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int n;
vector<vector<int>> ad;
vector<int> color;

void dfs(int u, int p, int c) {
  color[u] = c;
  for (int v : ad[u]) {
    if (v == p) continue;
    dfs(v, u, !c);
  }
}

int main() {
  cin >> n;
  ad.resize(n);
  color.resize(n, 0);
  int a, b;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    a--; b--;
    ad[a].push_back(b);
    ad[b].push_back(a);
  }
  dfs(0, 0, 0);
  int cnt = 0, c = 1;
  for (int i = 0; i < n; ++i) {
    if (color[i] == c) cnt++;
  }
  if (cnt < n / 2) {
    c = !c;
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (color[i] == c) ans.push_back(i);
  }
  for (int i = 0; i < n / 2; ++i) {
    if (i > 0) cout << " ";
    cout << ans[i] + 1;
  }
  cout << endl;
  
  return 0;
}