#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
	int H, W, h, w;
	cin >> H >> W >> h >> w;
	if (h >= H && w <= W) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}