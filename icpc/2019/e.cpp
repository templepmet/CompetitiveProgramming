#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int n;
int cube[9][9][9];
int piece[6][9][9];

void flip(int a[9][9]) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n / 2; ++j) {
			a[i][j] = a[i][n - 1 - j];
		}
	}
}

void rotate(int a[9][9], int arg) {
	int b[9][9];
	for (int t = 0; t < arg; ++t) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				b[i][j] = a[i][j];
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				a[j][n - i - 1] = b[i][j];
			}
		}
	}
}

void check(vector<int> &order, vector<int> &rot) {
	int tmp[6][9][9];
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				tmp[i][j][k] = piece[i][j][k];
			}
		}		
	}
	for (int i = 0; i < n; ++i) {
		if (rot[order[i]] >= 4) {
			flip(tmp[order[i]]);
		}
		rotate(tmp[order[i]], rot[order[i]] % 4);
	}

}

int main() {
	while (cin >> n && n > 0) {
		string f[6];
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> f[j];
				for (int k = 0; k < n; ++k) {
					piece[i][j][k] = (f[j][k] == '.' ? 1 : 0);
				}
			}
		}
		vector<int> order(6), rot(6);
		for (int i = 0; i < 6; ++i) {
			order[i] = i;
		}
		do {
			for (int i = 0; i < pow(8, 5); ++i) {
				int t = i;
				for (int j = 0; j < 6; ++j) {
					rot[j] = t % 8;
					t /= 8;
				}
				check(order, rot);
			}
		} while (next_permutation(order.begin(), order.end()));
	}

	return 0;
}