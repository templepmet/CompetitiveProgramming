#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    ll n, a, p = 1, m = 0;
    cin >> n >> a;
    for (int i = 1; i <= n; ++i) {
        if (m >= a && m - a + (n - i) * (p + 1) >= m + (n - i + 1) * p) {
            p++;
            m -= a;
        }
        else {
            m += p;
        }
    }
    cout << m << endl;

    return 0;
}