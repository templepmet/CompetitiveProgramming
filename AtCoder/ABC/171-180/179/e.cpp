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

ll n, x, m;
int v[100000];

int main() {
    cin >> n >> x >> m;
    vector<ll> a;
    a.push_back(x);
    fill(v, v + m, -1);
    v[x] = 0;
    v[0] = 0;
    for (int i = 0; i < m; ++i) {
        x = (x * x) % m;
        if (v[x] >= 0) {
            break;
        }
        a.push_back(x);
        v[x] = i + 1;
    }

    int id = v[x];
    ll ans = 0, sum = accumulate(a.begin() + id, a.end(), 0LL);

    if (x == 0) {
        cout << sum << endl;
        return 0;
    }

    int s = a.size() - id;
    ans += accumulate(a.begin(), a.begin() + id, 0LL);
    n -= id;
    if (n > 0) {
        ans += (n / s) * sum;
        ans += accumulate(a.begin() + id, a.begin() + id + (n % s), 0LL);
    }
    cout << ans << endl;

    return 0;
}