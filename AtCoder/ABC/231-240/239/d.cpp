#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

bool is_prime(ll n) {
		for (ll i = 2; i * i <= n; ++i) {
				if (n % i == 0) {
						return false;
				}
		}
		return true;
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	// a ~ b の中に c ~ d との和が全て素数とならない数が含まれていれば高橋が勝ち
	for (int i = a; i <= b; ++i) {
		bool f = false;
		for (int j = c; j <= d; ++j) {
			int n = i + j;
			if (is_prime(n)) {
				f = true;
				break;
			}
		}
		if (!f) {
			cout << "Takahashi" << endl;
			return 0;
		}
	}
	cout << "Aoki" << endl;

	return 0;
}