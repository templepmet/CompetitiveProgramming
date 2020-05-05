#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, a[100] = {}, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; i += 2) {
        ans += a[i] - a[i + 1];
    }
    cout << ans << endl;

    return 0;
}