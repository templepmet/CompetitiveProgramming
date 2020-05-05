#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int a[100000];
int g[100000];

int main() {
    int n, q, s;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0)
            g[i] = a[i];
        else
            g[i] = gcd(g[i - 1], a[i]);
    }
    
    for (int i = 0; i < q; ++i) {
        cin >> s;
        int x = gcd(s, g[n - 1]);
        if (x != 1) {
            cout << x << endl;
            continue;
        }
        int l = -1, r = n, m;
        while (l + 1 < r) {
            m = l + (r - l) / 2;
            if (gcd(g[m], s) == 1) {
                r = m;
            }
            else {
                l = m;
            }
        }
        if (gcd(g[r - 1], s) == 1)
            assert(0 == 1);
        cout << r + 1 << endl;
    }

    return 0;
}