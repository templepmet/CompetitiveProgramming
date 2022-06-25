#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
	set<int, greater<int>> q;
	// set<int> q;
	q.insert(1);
	q.insert(3);
	q.insert(4);
	q.insert(2);
	q.insert(5);
	for (auto it = q.begin(); it != q.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}