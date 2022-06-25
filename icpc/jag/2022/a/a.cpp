#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
	int n;
	while (cin >> n && n > 0) {
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int maxl = 1, l = 1;
		for (int i = 1; i < n; ++i) {
			if (v[i] == v[i - 1] + 1) {
				l++;
			}
			else {
				l = 1;
			}
			chmax(maxl, l);
		}
		cout << maxl << endl;
	}

	return 0;
}