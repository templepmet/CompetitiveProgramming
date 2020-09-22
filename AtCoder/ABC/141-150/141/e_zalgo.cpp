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

vector<int> z_algo(string s) {
    int l = s.size(), k;
    vector<int> z(l);
    z[0] = l;
    for (int i = 1, j = 0; i < l;) {
        while (i + j < l && s[j] == s[i + j]) j++;
        z[i] = j;
        if (j == 0) {
            i++;
            continue;
        }
        for (k = 1; k < j && k + z[k] < j; ++k) {
            z[i + k] = z[k];
        }
        i += k;
        j -= k;
    }
    return z;
}

int main() {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        auto z = z_algo(s);
        int l = s.size();
        for (int j = 0; j < l; ++j) {
            if (j >= z[j])
                chmax(ans, z[j]);
        }
        s = s.substr(1, l);
    }
    cout << ans << endl;

    return 0;
}