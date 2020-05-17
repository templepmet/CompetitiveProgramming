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

int main() {
    double a, b, h, m;
    double x1, x2, y1, y2, t1, t2;
    cin >> a >> b >> h >> m;
    t1 = M_PI * 2 * (h / 12 + m / 60 / 12);
    t2 = M_PI * 2 * m / 60;
    x1 = a * cos(t1);
    y1 = a * sin(t1);
    x2 = b * cos(t2);
    y2 = b * sin(t2);
    double ans = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}