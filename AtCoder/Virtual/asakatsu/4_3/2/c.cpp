#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, l[2000];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> l[i];
    sort(l, l + n);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sa = l[j] - l[i];
            int wa = l[i] + l[j];
            int p = upper_bound(l, l + n, sa) - l;
            int q = lower_bound(l, l + n, wa) - l;
            ans += max(0, q - max(p, j + 1));
        }
    }

    cout << ans << endl;

    return 0;
}