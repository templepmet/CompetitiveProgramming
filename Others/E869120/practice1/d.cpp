#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (((int)log10(i) + 1) % 2)
            ans++;
    }
    cout << ans << endl;

    return 0;
}