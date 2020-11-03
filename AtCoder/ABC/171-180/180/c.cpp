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

int main() {
    ll n;
    set<ll> ans;
    cin >> n;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans.insert(i);
            ans.insert(n / i);
        }
    }
    for (auto v : ans) {
        cout << v << endl;
    }

    return 0;
}