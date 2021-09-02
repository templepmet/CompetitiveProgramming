#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

const int MAX = 9999;

int main() {
	ll n, a, b, c;
	ll cnt = INF;
	cin >> n >> a >> b >> c;
	for (int i = 0; i <= MAX; ++i) {
		for (int j = 0; j <= MAX - i; ++j) {
			ll e = n - i * a - j * b;
			if (e >= 0 && e % c == 0) {
				chmin(cnt, i + j + (e / c));
			}
		}
	}
	cout << cnt << endl;

	return 0;
}