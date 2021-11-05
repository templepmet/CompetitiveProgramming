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
		int maxc = 0;
		do {
			int cnt = solve(b);
			if (chmax(maxc, cnt)) {
				cout << cnt << endl;
				for (int i = 0; i < n; ++i) {
					cout << b[i] << " ";	
				}
				cout << endl;
			}
		} while (next_permutation(b.begin(), b.end()));
	}

	return 0;
}