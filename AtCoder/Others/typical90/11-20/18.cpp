#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
	double t, l, x, y, e;
	int q;
	cin >> t;
	cin >> l >> x >> y;
	cin >> q;
	cout << fixed << setprecision(12);
	while (q--) {
		cin >> e;
		double ez = (l / 2) * (1 - cos(e / t * 2 * M_PI));
		double ey = -(l / 2) * sin(e / t * 2 * M_PI);
		double dy = y - ey;
		double dl = sqrt(x * x + dy * dy);
		double arg = atan2(ez, dl) * 180 / M_PI;
		cout << arg << endl;
	}

	return 0;
}