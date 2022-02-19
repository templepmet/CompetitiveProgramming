#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<ll, ll>;
using T = tuple<ll, ll, ll>;

const int MOD = 1e9 + 7;
const ll INF = 1e18 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
	ll n, m, a, b, c;
	cin >> n >> m;
	vector<T> ad;
	map<ll, ll> co;
	vector<ll> f;
	f.push_back(0);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		a--; b--;
		ad.emplace_back(a, b, c);
		ad.emplace_back(b, a, c);
		f.push_back(a);
		f.push_back(b);
		co[a] = INF;
		co[b] = INF;
	}
	sort(ad.begin(), ad.end());
	sort(f.begin(), f.end());
	f.erase(unique(f.begin(), f.end()), f.end());

	priority_queue<P, vector<P>, greater<P>> q;
	co[0] = 0;
	co[n - 1] = INF;
	q.emplace(0, 0);
	while (!q.empty()) {
		auto [c, h] = q.top();
		q.pop();
		for (auto it = lower_bound(ad.begin(), ad.end(), make_tuple(h, 0, 0)); it != ad.end(); ++it) {
			auto [a, b, t] = *it;
			if (a > h) {
				break;
			}
			bool update = false;
			update |= chmin(co[b], c + t);
			auto fit = lower_bound(f.begin(), f.end(), b);
			if (fit != f.begin()) {
				update |= chmin(co[b], co[*(fit - 1)] + h - *(fit - 1));
			}
			if (fit != f.end()) {
				update |= chmin(co[b], co[*(fit + 1)] + *(fit + 1) - h);
			}
			if (update) {
				q.emplace(co[b], b);
			}
		}
	}
	cout << co[n - 1] << endl;

	return 0;
}