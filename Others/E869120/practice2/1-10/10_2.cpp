#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int dp[40001];

int main() {
    int n, q, a[20], m[200];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> q;
    for (int i = 0; i < q; ++i)
        cin >> m[i];
    
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 40000; j >= 0; --j) {
            if (dp[j]) {
                dp[j + a[i]] = 1;
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << (dp[m[i]] ? "yes" : "no") << endl;
    }

    return 0;
}