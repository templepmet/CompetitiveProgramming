#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int n;
int ad[100][100];
int vi[100];

bool dfs(int u, int g) {
	if (u == g) {
		return true;
	}
	vi[u] = 1;
	for (int i = 0; i < n; ++i) {
		if (ad[u][i] && !vi[i]) {
			if (dfs(i, g)) return true;
		}
	}
	return false;
}

int main() {
	int q, c, u, v;
	cin >> n >> q;
	while (q--) {
		cin >> c >> u >> v;
		u--; v--;
		if (c == 1) {
			ad[u][v] = !ad[u][v];
			ad[v][u] = !ad[v][u];
		}
		else {
			fill(vi, vi + n, 0);
			if (dfs(u, v)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}

	return 0;
}