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
template<class T>
T gcd(T a, T b){return b ? gcd(b, a % b) : a;}

template<class T>
T lcm(T a, T b){return a / gcd(a, b) * b;}

int n, x[100], y[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (i == 1 && j == 6 && k == 8) {
                    // cout << "hoge" << endl;
                }
                int x1 = x[i] - x[k], x2 = x[i] - x[j];
                int y1 = y[i] - y[k], y2 = y[i] - y[j];
                int t1 = gcd(x1, y1);
                int t2 = gcd(x2, y2);
                if (t1 != 0) {
                x1 /= t1; y1 /= t1;
                }
                else {
                    if (x1 == 0) y1 = 1;
                    else if (y1 == 0) x1 = 1;
                }
                if (x1 < 0) {
                    x1 *= -1;
                    y1 *= -1;
                }

                if (t2 != 0) {
                x2 /= t2; y2 /= t2;
                }
                else {
                    if (x2 == 0) y2 = 1;
                    else if (y2 == 0) x2 = 1;
                }
                if (x2 < 0) {
                    x2 *= -1;
                    y2 *= -1;
                }
                if (x1 == x2 && y1 == y2) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}