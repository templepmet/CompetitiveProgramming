#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
	int n, m, l, r;
	cin >> n >> m;
	if (m > 1000) {
		return 0;
	}

	vector<P> e(m);
	for (int i = 0; i < m; ++i) {
		cin >> l >> r;
		e[i] = make_pair(min(l, r), max(l, r));
	}
	sort(e.begin(), e.end());
	set<P> st;
	ll cnt = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			if (e[i].first < e[j].first && e[i].second < e[j].second && e[j].first < e[i].second) {
				st.emplace(i, j);
				cnt++;
			}
		}
	}
	// cout << cnt << endl;

	cout << st.size() << endl;
	for (auto t : st) {
		cout << t.first << " " << t.second << endl;
	}

	return 0;
}