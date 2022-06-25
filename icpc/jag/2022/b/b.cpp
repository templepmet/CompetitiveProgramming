#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

ll get_top(set<int, greater<int>> maxheap, int m) {
	assert(maxheap.size() >= m);
	auto it = maxheap.begin();
	ll num = 0;
	for (int i = 0; i < m; ++i, ++it) {
		num = num * 10 + (*it);
	}
	return num;
}

void solve(int k) {
	string s;
	cin >> s;
	int n = s.size();
	stack<ll> ans;
	set<int, greater<int>> maxheap;
	for (int i = 0; i < n; i += k) {
		ll current_num = 0;
		for (int j = 0; j < k; ++j) {
			maxheap.insert(s[i + j] - '0');
			current_num = current_num * 10 + (s[i + j] - '0');
		}
		if (i == 0) {
			ans.push(current_num);
		}
		else {
			ll del_num = get_top(maxheap, k);
			if (current_num + ans.top() < del_num) {
				ans.pop();
				ans.push(del_num);
			}
			else {
				ans.push(current_num);
				maxheap.clear();
				for (int j = 0; j < k; ++j) {
					maxheap.insert(s[i + j] - '0');
				}
			}
		}
	}

	ll ansnum = 0;
	while (!ans.empty()) {
		ansnum += ans.top();
		ans.pop();
	}
	cout << ansnum << endl;
}

int main() {
	int k;
	while (cin >> k && k > 0) {
		solve(k);
	}

	return 0;
}