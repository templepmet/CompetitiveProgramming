#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> void chmax(T& a, T b){ if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b){ if (a > b) { a = b; } }

int m[1000001];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[a[i]]++;
    }
    sort(all(a));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (m[a[i]] == 1) {
            ans++;
        }
        if (m[a[i]] > 0) {
            for (int j = a[i]; j <= 1000000; j += a[i]) {
                m[j] = -1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}