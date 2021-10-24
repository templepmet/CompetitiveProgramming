#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

class RollingHash {
		static const ll base1 = 1009;
		static const ll base2 = 2009;
		static const ll mod1 = 1000000007;
		static const ll mod2 = 1000000009;
		vector<ll> hash1, hash2, pow1, pow2;

public:
		RollingHash(const string &s) {
				int n = s.size();
				hash1.assign(n + 1, 0);
				hash2.assign(n + 1, 0);
				pow1.assign(n + 1, 1);
				pow2.assign(n + 1, 1);
				for (int i = 0; i < n; ++i) {
						hash1[i + 1] = (hash1[i] * base1 + s[i]) % mod1;
						hash2[i + 1] = (hash2[i] * base2 + s[i]) % mod2;
						pow1[i + 1] = (pow1[i] * base1) % mod1;
						pow2[i + 1] = (pow2[i] * base2) % mod2;
				}
		}

		// [l, r)
		pair<ll, ll> get(int l, int r) const {
				ll res1 = ((hash1[r] - hash1[l] * pow1[r - l]) % mod1 + mod1) % mod1;
				ll res2 = ((hash2[r] - hash2[l] * pow2[r - l]) % mod2 + mod2) % mod2;
				return make_pair(res1, res2);
		}

		pair<ll, ll> hash() const {
				return get(0, hash1.size() - 1);
		}
};

string substr(const string &str, int S1, int S2 = -1){
    if(S2 == -1)return str.substr(S1);
    return str.substr(S1, S2-S1);
}

bool is_kaibun(int i, int j, int k, int l) {
	return false;
}

int main() {
	string s = "burisyabusyaburibu";
	RollingHash sh(s);
	cout << sh.get(0, 2).first << endl;
	cout << sh.get(s.size() - 2, s.size()).first << endl;

	return 0;
}