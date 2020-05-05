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

double p;

double calc(double x) {
    return x + p * pow(2LL, -(x / 1.5));
}

int main() {
    cin >> p;
    double l = 0, r = p, ll, rr;
    for (int i = 0; i < 10000; ++i) {
        ll = l + (r - l) / 3;
        rr = l + (r - l) * 2 / 3;
        if (calc(ll) < calc(rr)) {
            r = rr;
        }
        else {
            l = ll;
        }
    }
    cout << fixed << setprecision(10);
    cout << calc(l) << endl;

    return 0;
}