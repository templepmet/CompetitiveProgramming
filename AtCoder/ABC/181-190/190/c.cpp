#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n, m, k, a[100], b[100], c[16], d[16];
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> c[i] >> d[i];
    }
    int p[101], ans = 0;
    for (int t = 0; t < (1 << k); ++t) {
        fill(p, p + 101, 0);
        for (int i = 0; i < k; ++i) {
            if ((t >> i) & 1) {
                p[c[i]]++;
            }
            else {
                p[d[i]]++;
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            if (p[a[i]] && p[b[i]]) {
                cnt++;
            }
        }
        chmax(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}