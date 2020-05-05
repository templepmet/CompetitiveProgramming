#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

int main() {
    int h, w, k, s[10][1000];
    cin >> h >> w >> k;
    char c;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> c;
            s[i][j] = c - '0';
        }
    }
    int ans = INF;
    for (int l = 0; l < 1 << (h - 1); ++l) {
        int cnt[10] = { 0 };
        int sum = 0;
        for (int j = 0, bj = 0; j < w; ++j) {
            int suf = 0;
            for (int i = 0, lt = l; i < h; ++i, lt >>= 1) {
                cnt[suf] += s[i][j];
                if (cnt[suf] > k) {
                    if (j == bj) {
                        j = w;
                        sum = INF;
                        break;
                    }
                    fill(cnt, cnt + h, 0);
                    sum++;
                    bj = j;
                    j--;
                    break;
                }
                if (lt & 1) {
                    if (j == 0)
                        sum++;
                    suf++;
                }
            }
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;

    return 0;
}