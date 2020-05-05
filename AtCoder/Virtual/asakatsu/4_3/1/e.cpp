#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, ans = INF;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, abs(i - (n / i)) + n - i * (n / i));
    }
    cout << ans << endl;

    return 0;
}