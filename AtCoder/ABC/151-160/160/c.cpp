#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int a[200000];

int main() {
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int maxd = 0;
    for (int i = 0; i < n - 1; ++i) {
        maxd = max(maxd, abs(a[i] - a[(i + 1) % n]));
    }
    maxd = max(maxd, (a[0] - a[n - 1] + k) % k);
    cout << k - maxd << endl;

    return 0;
}