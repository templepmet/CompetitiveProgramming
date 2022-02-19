#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int, int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	vector<P> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		v[i] = make_tuple(a[i] + b[i], a[i], n - i, i);
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < n; ++i) {
		if (i > 0) cout << " ";
		cout << get<3>(v[i]) + 1;
	}
	cout << endl;

	return 0;
}