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

double a[200000];
int n;
ll k;

bool isok(double m) {
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (ll)max(0.0, ceil(a[i] / m)) - 1;
    }
    if (sum <= k)
        return true;
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    double l = 0, r = 1e9, m;
    for (int i = 0; i < 100; ++i) {
        m = (l + r) / 2;
        if (isok(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << (ll)ceil(l) << endl;

    return 0;
}