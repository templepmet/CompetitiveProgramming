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
	int y;
	string kyogi, medal;
	while (cin >> n && n > 0) {
		vector<int> saita(2100, 0), gold(2100, 0);
		for (int i = 0; i < n; ++i) {
			cin >> y >> kyogi >> medal;
			saita[y]++;
			if (medal == "Gold") {
				gold[y]++;
			}
		}
		cout << max_element(gold.begin(), gold.end()) - gold.begin() << " ";
		cout << max_element(saita.begin(), saita.end()) - saita.begin() << endl;
	}

	return 0;
}