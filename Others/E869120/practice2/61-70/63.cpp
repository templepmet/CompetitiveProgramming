#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define INF (1e9 + 1)

int a[300][300];
int d[300][300];

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n;
    cin >> n;
    fill(d[0], d[n], INF);
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; ++i) {
        d[i][i] = 0;
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (i < j)
                v.push_back(make_tuple(a[i][j], i, j));
        }
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (auto t : v) {
        auto [val, i, j] = t;
        if (d[i][j] < val) {
            cout << -1 << endl;
            return 0;
        }
        if (d[i][j] > val) {
            d[i][j] = d[j][i] = val;
            ans += val;
        }
        for (int k = 0; k < n; ++k) {
            chmin(d[k][j], d[k][i] + d[i][j]);
            chmin(d[j][k], d[k][j]);
            chmin(d[i][k], d[i][j] + d[j][k]);
            chmin(d[k][i], d[i][k]);
        }
    }
    cout << ans << endl;

    return 0;
}