#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n, c, p;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        cin >> c >> p;
        a[c - 1][i + 1] = p;
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j + 1] += a[i][j];
        }
    }
    int q, l, r;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        int s1 = a[0][r] - a[0][l - 1];
        int s2 = a[1][r] - a[1][l - 1];
        cout << s1 << " " << s2 << endl;
    }

    return 0;
}