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

int solve(vector<int> v) {
	int cnt = 0;
	while (1) {
		if (!reduce(v)) {
			break;
		}
		cnt++;
	}
	return cnt;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> b(n);
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
		}
		sort(b.begin(), b.end());
		vector<int> v, vmax;
		v.push_back(b[0]);
		for (int i = 1; i < n; ++i) {
			int maxc = -1;
			for (int j = i; j >= 0; --j) {
				vector<int> tmp;
				for (int k = 0; k < j; ++k) {
					tmp.push_back(v[k]);
				}
				tmp.push_back(b[i]);
				for (int k = j; k < i; ++k) {
					tmp.push_back(v[k]);
				}
				int cnt = solve(tmp);
				if (chmax(maxc, cnt)) {
					vmax = tmp;
				}
			}
			v = vmax;
			for (int j = 0; j < i + 1; ++j) {
				cout << v[j] << " ";
			}
			cout << endl;
		}
		cout << solve(v) << endl;
	}

	return 0;
}