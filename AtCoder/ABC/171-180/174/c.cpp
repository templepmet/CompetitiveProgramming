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
    int k, t = 0, ans = 0;
    cin >> k;
    do {
        bool f = true;
        for (int i = 0; i <= 9; ++i) {
            if ((t + k * i) % 10 == 7) {
                t = (t + k * i) / 10;
                f = false;
                break;
            }
        }
        if (f) {
            ans = -1;
            break;
        }
        ans++;
    } while (t > 0);

    cout << ans << endl;

    return 0;
}