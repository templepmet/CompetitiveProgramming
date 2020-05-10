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

int a[300000], b[300000], d[300000];

int main() {
    int n;
    ll k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    int s = 0;
    ll cnt = 0;
    while (1) {
        d[cnt] = s;
        if (cnt == k) {
            cout << s + 1 << endl;
            return 0;
        }
        if (b[s]) {
            break;
        }
        b[s] = 1;
        s = a[s];
        cnt++;
    }
    k -= cnt;
    for (int i = 0; i < n; ++i) {
        if (d[i] == s) {
            for (int j = i + 1; j < n; ++j) {
                if (d[j] == s) {
                    cout << d[i + k % (j - i)] + 1 << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}