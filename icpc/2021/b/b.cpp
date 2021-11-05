#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int w, h, k;
int x[200], y[200], n[200];
int f[100][100];
int uans[100], lans[100];
bool update;

void dfsl(int idy);

void dfsu(int idx) {
	for (int i = 0; i < h; ++i) {
		if (f[i][idx] != INF && lans[i] == INF) {
			lans[i] = f[i][idx] - uans[idx];
			update = true;
			dfsl(i);
		}
	}
}

void dfsl(int idy) {
	for (int j = 0; j < w; ++j) {
		if (f[idy][j] != INF && uans[j] == INF) {
			uans[j] = f[idy][j] - lans[idy];
			update = true;
			dfsu(j);
		}
	}
}

int main() {
	while (cin >> w >> h && w > 0) {
		k = w + h - 1;
		fill(f[0], f[h], INF);
		fill(uans, uans + w, INF);
		fill(lans, lans + h, INF);
		for (int i = 0; i < k; ++i) {
			cin >> x[i] >> y[i] >> n[i];
			x[i]--;
			y[i]--;
			f[y[i]][x[i]] = n[i];
		}
		uans[0] = 0;
		dfsu(0);
		bool ok = true;
		for (int i = 0; i < h; ++i) {
			if (lans[i] == INF) {
				ok = false;
			}
		}
		for (int j = 0; j < w; ++j) {
			if (uans[j] == INF) {
				ok = false;
			}
		}
		if (ok) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	};

	return 0;
}