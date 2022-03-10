#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

// 100000000000
//> 99999999999
// f(m) + b = m

ll n, b, l;
int buf[20];
ll ans;

void check(int d) {
  ll fm = 1;
  for (int i = 0; i < d; ++i) {
    fm *= buf[i];
  }
  ll fmb = fm + b;
  if (fmb > n) {
    return;
  }
  string fmbs = to_string(fmb);
  int fmbsl = fmbs.size();
  if (fmbsl != d) return;
  int c1[10] = {};
  int c2[10] = {};
  for (int i = 0; i < d; ++i) {
    c1[buf[i]]++;
    c2[fmbs[i] - '0']++;
  }
  bool f = true;
  for (int i = 0; i < 10; ++i) {
    if (c1[i] != c2[i]) {
      f = false;
    }
  }
  if (f) {
    ans++;
  }
}

void dfs(int d, int fn) {
  if (d > 0) {
    check(d);
  }
  if (d == l) {
    return;
  }
  for (int i = fn; i < 10; ++i) {
    buf[d] = i;
    dfs(d + 1, i);
  }
}

int main() {
  cin >> n >> b;
  l = to_string(n).size();
  dfs(0, 0);
  cout << ans << endl;
  
  return 0;
}