#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// z[i] : sとs[i:]の最長共通接頭辞の長さ
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
// O(|T|+|S|)でSの中にあるTを探す

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        auto z = z_algo(s.substr(i));
        for (int j = 0; j < n - i; ++j) {
            chmax(ans, min(j, z[j]));
        }
    }

    cout << ans << endl;

    return 0;
}