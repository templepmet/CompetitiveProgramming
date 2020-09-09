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

int mod[200001];
ll a[2020];

int main() {
    string s;
    cin >> s;

    int p = 2019, t = 0, b = 1, l = s.size();
    a[0] = 1;
    for (int i = l - 1; i >= 0; --i) {
        t += (s[i] - '0') * b;
        t %= p;
        b *= 10;
        b %= p;
        a[t]++;
    }

    ll ans = 0;
    for (int i = 0; i <= p; ++i) {
        ans += (a[i] * (a[i] - 1) / 2);
    }
    cout << ans << endl;

    return 0;
}