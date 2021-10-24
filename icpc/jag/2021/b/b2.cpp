#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int a[100][100];

int main() {
	int h, w;
	while (cin >> h >> w && h > 0 && w > 0) {
		double sum = 0;
		double sum_vi_i = 0;
		double sum_vj_j = 0;
		string f[100];
		for (int i = 0; i < h; ++i) {
			cin >> f[i];
			for (int j = 0; j < w; ++j) {
				a[i][j] = f[i][j] - '0';
			}
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				sum += a[i][j];
				sum_vi_i += a[i][j] * (i + 1);
				sum_vj_j += a[i][j] * (j + 1);
			}
		}
		double r = sum_vi_i / sum;
		double c = sum_vj_j / sum;
		cout << fixed << setprecision(12);
		cout << r << " " << c << endl;
	}

	return 0;
}