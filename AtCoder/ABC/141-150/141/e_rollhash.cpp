#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

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

int main() {
    int n;
    string s;
    cin >> n >> s;
    RollingHash rh(s);
    int l = 0, r = n, m;
    while (r - l > 1) {
        m = (l + r) / 2;
        bool f = false;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (i + m <= j && j + m <= n && rh.get(i, i + m) == rh.get(j, j + m)) {
                    f = true;
                }
            }
        }
        if (f) {
            l = m;
        }
        else {
            r = m;
        }
    }

    cout << l << endl;

    return 0;
}