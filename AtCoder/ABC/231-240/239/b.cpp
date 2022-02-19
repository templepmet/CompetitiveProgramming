#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
	ll x;
	cin >> x;
	if (x % 10 == 0) {
		cout << x / 10 << endl;
	}
	else if (x > 0) {
		cout << x / 10 << endl;
	}
	else {
		cout << x / 10 - 1 << endl;
	}

	return 0;
}