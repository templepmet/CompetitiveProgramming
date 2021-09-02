#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, ll>> dt(n);
    int d, c, s;
    for (int i = 0; i < n; ++i) {
        cin >> d >> c >> s;
        dt[i] = make_tuple(d, c, s);
    }
    sort(dt.begin(), dt.end());
    
    vector<ll> dp(5001, -1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        auto [d, c, s] = dt[i];
        for (int j = d; j >= 0; --j) {
            if (dp[j] >= 0 && j + c <= d) {
                chmax(dp[j + c], dp[j] + s);
            }
        }
    }
    ll ans = *max_element(dp.begin(), dp.end());
    cout << ans << endl;

    return 0;
}

// O(N Dmax)