#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int m[6] = {500, 100, 50, 10, 5, 1};
int k[6] = {0, 0, 1, 0, 1, 0};

int cnt(int a, int b) {
	int d = b - a;
	int c = 0;
	for (int i = 0; i < 6; ++i) {
		while (d >= m[i]) {
			d -= m[i];
			c += k[i];
		}
	}
	return c;
}

int main() {
	int n, a, b, ans = 0;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		ans += cnt(a, b);
	}
	cout << ans << endl;

	return 0;
}