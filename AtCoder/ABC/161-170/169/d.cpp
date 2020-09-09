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

int main() {
    ll n, m;
    map<int, int> mp;
    cin >> n;
    m = n;
    for (ll i = 2; i * i <= m; ++i) {
        while (n % i == 0) {
            n /= i;
            mp[i]++;
        }
    }
    if (n > 1) {
        mp[n]++;
    }
    int ans = 0;
    for (auto t : mp) {
        int cnt = t.second;
        int k = 1;
        while (k <= cnt) {
            ans++;
            cnt -= k;
            k++;
        }
    }
    cout << ans << endl;

    return 0;
}