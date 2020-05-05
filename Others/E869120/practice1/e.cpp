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
        if (i % 2 == 0)
            continue;
        int cnt = 0;
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0)
                cnt++;
        }
        if (cnt == 8)
            ans++;
    }
    cout << ans << endl;

    return 0;
}