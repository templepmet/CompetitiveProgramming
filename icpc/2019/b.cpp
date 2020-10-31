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

int h, w;
string r[50], s;

int main() {
    while (cin >> h >> w && h > 0) {
        for (int i = 0; i < h; ++i) {
            cin >> r[i];
        }
        cin >> s;
        int ans = 0;
        int y = 0, x = 0;
        for (char c : s) {
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    if (r[i][j] == c) {
                        ans += abs(y - i) + abs(x - j) + 1;
                        y = i;
                        x = j;
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}