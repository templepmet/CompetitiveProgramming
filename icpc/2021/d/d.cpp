#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

bool reduce(vector<int> &v) {
	int n = v.size();
	if (n < 3) {
		return false;
	}
	if (v[0] > 0 && v[1] > 0 && v[2] > 0) {
		v[0]--;
		v[1]--;
		v[2]--;
	}
	else {
		return false;
	}

	vector<int> ret;
	for (int i = 0; i < n; ++i) {
		if (v[i] > 0) {
			ret.push_back(v[i]);
		}
	}
	v = ret;
	return true;
}

vector<int> arrange(vector<int> &v) {
	int n = v.size();
	sort(v.rbegin(), v.rend());

	int m = (n + 2) / 3;
	vector<vector<int>> tmp(m);
	for (int i = 0; i < n; ++i) {
		tmp[i % m].push_back(v[i]);
	}
	for (int i = 0; i < m; ++i) {
		sort(tmp[i].rbegin(), tmp[i].rend());
	}

	vector<int> ret;
	for (int i = m - 1; i >= 0; --i) {
		for (auto t : tmp[i]) {
			ret.push_back(t);
		}
	}
	return ret;
}

int main() {
	int n;
	while (cin >> n && n > 0) {
		vector<int> b(n);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
			sum += b[i];
		}
		cout << sum << " "  << sum / 3 << endl;
		
		b = arrange(b);

		int cnt = 0;
		while (1) {
			if (!reduce(b)) {
				break;
			}
			cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}