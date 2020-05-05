#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

int h, w, k;
int s[10][1000];

int main() {
    cin >> h >> w >> k;
    char c;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> c;
            s[i][j] = c - '0';
        }
    }
    
    int bunkatsu[10] = { 0 };
    int ans = INF;
    for (int l = 0; l < 1 << (h - 1); ++l) {
        int t = 0, sum = 0;
        for (int ll = 0, lt = l; lt > 0; ++ll) {
            if (lt & 1) {
                bunkatsu[t++] = ll;
                sum++;
            }
            lt >>= 1;
        }
        if (t == 0) t++;
        bunkatsu[t] = h;
        int before = 0;
        for (int j = before; j < w; ++j) {
            int cnt[10] = { 0 };
            for (int tt = 0; tt < t; ++tt) {
                for (int i = (tt == 0 ? 0 : bunkatsu[tt]); i < bunkatsu[tt + 1]; ++i) {
                    cnt[tt] += s[i][j];
                }
                if (cnt[tt] > k) {
                    sum++;
                    before = j;
                    break;
                }
            }
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;

    return 0;
}