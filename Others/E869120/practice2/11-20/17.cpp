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
    int k, r[8], c[8], a[8];
    cin >> k;
    rep(i, k) {
        cin >> r[i] >> c[i];
    }
    rep(i, 8) a[i] = i;
    do {
        // 縦横が重ならないことは保証されている→斜めのみ調べる
        int d1[15] = { 0 }, d2[15] = { 0 };
        bool f = true;
        rep(i, k) {
            if (a[r[i]] != c[i])
                f = false;
        }
        rep(i, 8) {
            d1[a[i] - i + 7]++;
            d2[a[i] + i]++;
        }
        rep(i, 14) {
            if (d1[i] > 1 || d2[i] > 1)
                f = false;
        }
        if (!f)
            continue;
        rep(i, 8) {
            rep(j, 8) {
                bool isfind = false;
                rep(l, 8) {
                    if (l == i && a[l] == j)
                        isfind = true;
                }
                cout << (isfind ? 'Q' : '.');
            }
            cout << endl;
        }
        
    } while (next_permutation(a, a + 8));

    return 0;
}