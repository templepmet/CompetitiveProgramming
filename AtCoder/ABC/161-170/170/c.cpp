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

int main() {
    int x, n, p, a[100] = { 2 };
    cin >> x >> n;
    while (n--) {
        cin >> p;
        if (p - x >= 0) {
            a[p - x] += 1;
        }
        else {
            a[x - p] += 2;
        }
    }
    for (int i = 0;;++i) {
        if (a[i] != 3) {
            if (a[i] == 2) {
                x += i;
            }
            else {
                x -= i;
            }
            cout << x << endl;
            break;
        }
    }

    return 0;
}