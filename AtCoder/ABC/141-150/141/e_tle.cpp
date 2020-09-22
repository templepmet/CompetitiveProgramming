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

int main() {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    map<pair<int, int>, vector<int>, greater<pair<int, int>>> mp;

    for (int i = 0; i < n; ++i) {
        int h = 0;
        for (int j = 0; i + j < n; ++j) {
            h += s[i + j] - 'a' + 1;
            mp[make_pair(j + 1, h)].push_back(i);
        }
    }
    for (auto t : mp) {
        int l = t.first.first;
        auto v = t.second;
        int k = v.size();
        if (k < 2)
            continue;
        for (int i = 0; i < k; ++i) {
            for (int j = i + 1; j < k; ++j) {
                if (min(v[i], v[j]) + l > max(v[i], v[j]))
                    continue;
                if (s.substr(v[i], l) == s.substr(v[j], l)) {
                    cout << l << endl;
                    return 0;
                }
            }
        }
    }

    cout << 0 << endl;

    return 0;
}