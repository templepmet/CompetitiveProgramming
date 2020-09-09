#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> void chmax(T& a, T b){ a>b?:a=b; }
template<class T> void chmin(T& a, T b){ a<b?:a=b; }

int main() {
    int h, w, k;
    string s[6];
    cin >> h >> w >> k;
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    int ans = 0;
    for (int t = 0; t < (1 << (h + w)); ++t) {
        int cnt = 0;
        for (int i = 0; i < h; ++i) {
            if (t & (1 << i))
                continue;
            for (int j = 0; j < w; ++j) {
                if (t & (1 << (h + j)))
                    continue;
                if (s[i][j] == '#')
                    cnt++;
            }
        }
        if (cnt == k)
            ans++;
    }

    cout << ans << endl;

    return 0;
}