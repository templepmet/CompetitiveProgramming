#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

ll pow_orig(ll a, ll b) {
		if (b == 0) return 1;
		if (b % 2) return (a * pow_orig(a, b - 1));
		return pow_orig(a * a, b / 2);
}

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	cout << (a < pow_orig(c, b) ? "Yes" : "No") << endl;

	return 0;
}