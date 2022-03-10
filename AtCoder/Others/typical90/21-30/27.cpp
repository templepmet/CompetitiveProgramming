#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
  int n;
  string s;
  set<string> st;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    if (st.find(s) == st.end()) {
      cout << i + 1 << endl;
      st.insert(s);
    }
  }
  
  return 0;
}