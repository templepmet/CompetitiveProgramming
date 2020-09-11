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

int h, w, m;
int y[300000], x[300000];
int ch[300001], cw[300001];

int main() {
    cin >> h >> w >> m;
    for (int i = 0; i < m; ++i) {
        cin >> y[i] >> x[i];
        ch[y[i]]++;
        cw[x[i]]++;
    }
    int maxh = *max_element(ch, ch + h + 1);
    int maxw = *max_element(cw, cw + w + 1);
    int cnth = count(ch, ch + h + 1, maxh);
    int cntw = count(cw, cw + w + 1, maxw);
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        if (ch[y[i]] == maxh && cw[x[i]] == maxw)
            cnt++;
    }
    cout << maxh + maxw + (cnt == cnth * cntw ? -1 : 0) << endl;

    return 0;
}