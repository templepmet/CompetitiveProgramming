#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

int main() {
    int n, x[100], sum = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        sum += x[i];
        ans += x[i] * x[i];
    }
    int p = round(sum / (double)n);
    ans += -2 * p * sum + n * p * p;
    cout << ans << endl;

    return 0;
}