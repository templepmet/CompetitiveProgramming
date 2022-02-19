#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int n;
vector<vector<int>> rk;
vector<vector<int>> ad;

void dfs(int u, int p) {
	for (int v : ad[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
	for (int v : ad[u]) {
		if (v == p) continue;
		rk[u].insert(rk[u].end(), rk[v].begin(), rk[v].end());
	}
	sort(rk[u].rbegin(), rk[u].rend());
	vector<int> tmp;
	copy(rk[u].begin(), rk[u].begin() + min((int)rk[u].size(), 20), back_inserter(tmp));
	rk[u] = tmp;
}

int main() {
	int q, x, a, b, v, k;
	cin >> n >> q;
	ad.resize(n);
	rk.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> x;
		rk[i].push_back(x);
	}
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		a--; b--;
		ad[a].push_back(b);
		ad[b].push_back(a);
	}
	dfs(0, 0);
	while (q--) {
		cin >> v >> k;
		v--; k--;
		cout << rk[v][k] << endl;
	}

	return 0;
}