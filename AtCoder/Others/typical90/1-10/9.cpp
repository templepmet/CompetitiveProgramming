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
    vector<vector<int>> p(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> p[i][0] >> p[i][1];
    }
    vector<double> arg(n - 1);
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0, k = 0; j < n; ++j) {
            if (i == j) continue;
            arg[k++] = atan2(p[j][1] - p[i][1], p[j][0] - p[i][0]);
        }
        sort(arg.begin(), arg.end());
        for (int j = 0; j < n - 1; ++j) {
            double best = arg[j] + M_PI;
            if (best > 2 * M_PI)
                best -= 2 * M_PI;
            auto it = upper_bound(arg.begin(), arg.end(), best);
            double calc = 0;
            if (it != arg.end()) {
                calc = abs(*it - arg[j]);
                chmax(ans, min(calc, 2 * M_PI - calc));
            }
            if (it != arg.begin()) {
                calc = abs(*(it - 1) - arg[j]);
                chmax(ans, min(calc, 2 * M_PI - calc));
            }
        }
    }
    cout << fixed << setprecision(12);
    cout << ans * 180 / M_PI << endl;

    return 0;
}