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
    if (n > 20) {
        return 0;
    }
    vector<tuple<int, int, ll>> dt(n);
    int d, c, s;
    for (int i = 0; i < n; ++i) {
        cin >> d >> c >> s;
        dt[i] = make_tuple(d, c, s);
    }
    sort(dt.begin(), dt.end());

    ll ans = 0;
    for (int t = 0; t < (1 << n); ++t) {
        ll score = 0;
        int day = 1;
        for (int i = 0; i < n; ++i) {
            if (t & (1 << i)) {
                auto [d, c, s] = dt[i];
                if (day + c - 1 <= d) {
                    day += c;
                    score += s;
                }
            }
        }
        chmax(ans, score);
    }
    cout << ans << endl;

    return 0;
}