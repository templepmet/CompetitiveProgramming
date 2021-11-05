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
		for (int i = 1; i < n; ++i) {
			int maxc = 0;
			vector<int> vmax;
			for (int j = i; j >= 0; --j) {
				vector<int> c = b;
				int tmp = c[i];
				for (int k = i; k > j; --k) {
					c[k] = c[k - 1];
				}
				c[j] = tmp;
				int cnt = solve(c);
				if (chmax(maxc, cnt)) {
					vmax = c;
				}
			}
			b = vmax;
			for (int i = 0; i < n; ++i) {
				cout << b[i] << " ";
			}
			cout << endl;
		}		
		cout << solve(b) << endl;
	}

	return 0;
}