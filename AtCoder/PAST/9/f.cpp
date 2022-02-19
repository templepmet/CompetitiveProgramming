#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
	int a, b;
	int f[9][9] = {};
	string s[3];
	cin >> a >> b;
	a-- ; b--;
	for (int i = 0; i < 3; ++i) {
		cin >> s[i];
	}
	queue<P> q;
	f[a][b] = 1;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				int ny = y + i - 1;
				int nx = x + j - 1;
				if (ny < 0 || nx < 0 || ny >= 9 || nx >= 9 || s[i][j] == '.') {
					continue;
				}
				if (f[ny][nx] == 0) {
					f[ny][nx] = 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			ans += f[i][j];
		}
	}
	cout << ans << endl;

	return 0;
}