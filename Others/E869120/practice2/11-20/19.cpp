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
    int d, n, m, k;
    cin >> d >> n >> m;
    vector<int> store(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        cin >> store[i];
    }
    store[n] = d;
    sort(all(store));
    int ans = 0;
    while (m--) {
        cin >> k;
        int s = lower_bound(store.begin(), store.begin() + n, k) - store.begin();
        ans += min(store[s] - k, k - store[s - 1]);
    }
    cout << ans << endl;

    return 0;
}