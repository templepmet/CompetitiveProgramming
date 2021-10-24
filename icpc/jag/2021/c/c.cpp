#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }


int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int dy[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int f[8][8];
int h, w;
int ans = 0;

int stx[4][3] = {
	{0, 1, 1 },
	{0, 0, 1 },
	{0, 1, 0 },
	{0, 0, -1 }
};

int sty[4][3] = {
	{0, 0, 1 },
	{0, 1, 1 },
	{0, 0, 1},
	{0, 1, 1}
};

void dfs(int y, int x, int c) {
	bool space = false;
	int nx, ny;
	for (int i = y; i < h; ++i) {
		for (int j = (i == y ? x : 0); j < w; ++j) {
			if (f[i][j] == 0) {
				for (int k = 0; k < 4; ++k) {
					bool is_set = true;
					for (int l = 0; l < 3; ++l) {
						nx = j + stx[k][l];
						ny = i + sty[k][l];
						if (nx < 0 || nx >= w || ny < 0 || ny >= h || f[ny][nx]) {
							is_set = false;
							break;
						}
					}
					if (is_set) {
						for (int l = 0; l < 3; ++l) {
							nx = j + stx[k][l];
							ny = i + sty[k][l];
							f[ny][nx] = c;
						}
						dfs(i, j, c + 1);
						for (int l = 0; l < 3; ++l) {
							nx = j + stx[k][l];
							ny = i + sty[k][l];
							f[ny][nx] = 0;
						}
					}
				}
				return;
			}
		}
	}

	// for (int i = 0; i < h; ++i) {
	// 	for (int j = 0; j < w; ++j) {
	// 		cout << f[i][j];
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	ans++;
}

int main() {
	string s[8];
	while (cin >> h >> w && h > 0 && w > 0) {
		for (int i = 0; i < h; ++i) {
			cin >> s[i];
			for (int j = 0; j < w; ++j) {
				if (s[i][j] == '.') {
					f[i][j] = 0;
				}
				else {
					f[i][j] = 1;
				}
			}
		}
		ans = 0;
		dfs(0, 0, 2);
		cout << ans << endl;
	}
	

	return 0;
}