#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int a[200000];

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ans = 0, dp = 0, dpmax = 0, p = 0, dv = 0;
    for (int i = 0; i < n; ++i) {
        dv += a[i];
        dp += a[i];
        chmax(dpmax, dp);
        chmax(ans, p + dpmax);
        p += dv;
        chmax(ans, p);
    }
    cout << ans << endl;

    return 0;
}