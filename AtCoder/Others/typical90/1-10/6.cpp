#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n, k;
    string s, t;
    cin >> n >> k >> s;
    t = string(k, 'z');
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        l = max(0, k - (n - i));
        int j = upper_bound(t.begin() + l, t.begin() + r, s[i]) - t.begin();
        if (j < r) {
            t[j] = s[i];
            r = j + 1;
        }
        else if (j == r && r < k) {
            t[j] = s[i];
            r++;
        }
    }
    cout << t << endl;

    return 0;
}