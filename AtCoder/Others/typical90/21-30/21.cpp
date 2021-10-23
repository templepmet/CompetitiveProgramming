#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

const int MAXV = 100000;

int n, m;
vector<int> fw[MAXV], re[MAXV];
vector<int> vs;
bool vi[MAXV];
int cmp[MAXV];

void dfs_fw(int u) {
	vi[u] = true;
	for (auto v : fw[u]) {
		if (!vi[v]) {
			dfs_fw(v);
		}
	}
	vs.push_back(u);
}

void dfs_re(int u, int c) {
	vi[u] = true;
	cmp[u] = c;
	for (auto v : re[u]) {
		if (!vi[v]) {
			dfs_re(v, c);
		}
	}
}

int main() {
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a--; b--;
		fw[a].push_back(b);
		re[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		if (!vi[i]) {
			dfs_fw(i);
		}
	}

	fill(vi, vi + n, false);
	int k = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (!vi[vs[i]]) {
			dfs_re(vs[i], ++k);
		}
	}

	ll ans = 0;
	vector<ll> cnt(k);
	for (int i = 0; i < n; ++i) {
		cnt[cmp[i] - 1]++;
	}
	for (int i = 0; i < k; ++i) {
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	cout << ans << endl;

	return 0;
}
