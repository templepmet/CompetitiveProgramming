#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

ll g[100001];

int main() {
    int t;
    cin >> t;

    g[1] = 1;
    for (ll i = 2, d = 1; i <= 100000; ++i) {
        g[i] = g[i - 1] + d++;
    }
    while (t--) {
        ll n, k;
        cin >> n >> k;
        string s(n, 'a');
        int suf = upper_bound(g, g + 100000, k) - g - 1;
        s[n - 1 - suf] = 'b';
        s[n - 1 - (k - g[suf])] = 'b';
        cout << s << endl;
    }

    return 0;
}