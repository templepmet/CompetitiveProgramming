#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
	int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if (max(abs(x1 - x2), abs(y1 - y2)) > 4) {
		cout << "No" << endl;
		return 0;
	}

	bool f = false;
	for (int x = min(x1, x2) - 2; x <= max(x1, x2) + 2; x++) {
		for (int y = min(y1, y2) - 2; y <= max(y1, y2) + 2; y++) {
			bool f1 = false, f2 = false;
			for (int i = 0; i < 8; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx == x1 && ny == y1) {
					f1 = true;
				}
				if (nx == x2 && ny == y2) {
					f2 = true;
				}
			}
			if (f1 && f2) {
				f = true;
			}
		}
	}
	if (f) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}