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

int l[100000];
int a[100000];
int b[100000];

int main() {
    int n, cnt = 0;
    cin >> n;
    rep(i, n) cin >> a[i];

    while (1) {
        bool f = true;
        fill(l, l + n, INF);
        rep(i, n) {
            if (a[i] < 0)
                continue;
            f = false;
            int j = lower_bound(l, l + n, a[i]) - l;
            l[j] = a[i];
            b[j] = i;
        }
        if (f) break;

        int lis = lower_bound(l, l + n, INF) - l;
        rep(i, lis) a[b[i]] = -1;
        cnt++;
    }
    cout << cnt << endl;

    return 0;
}