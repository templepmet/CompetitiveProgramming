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
	char p;
	string v;
	map<char, int> f;
	for (int i = 0; i < 6; ++i) {
		f['A' + i] = INF;
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p >> v;
		if (v == "AC") {
			chmin(f[p], i + 1);
		}
	}
	for (int i = 0; i < 6; ++i) {
		cout << f['A' + i] << endl;
 	}

	return 0;
}