#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

bool c(char c) {
	int v = c - '0';
	if (1 <= v && v <= 5) return true;
	return false;
}

int main() {
	string s;
	int ans = 500;
	cin >> s;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == s[i - 1]) {
			ans += 301;
		}
		else if ( ( c(s[i]) && c(s[i - 1]) ) || (!c(s[i]) && !c(s[i - 1])) ) {
			ans += 210;
		}
		else {
			ans += 100;
		}
	}
	cout << ans << endl;

	return 0;
}