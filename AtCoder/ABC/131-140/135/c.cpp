#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n, b;
    ll ans = 0;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b;
        ans += min(a[i], b);
        b -= min(a[i], b);
        ans += min(a[i + 1], b);
        a[i + 1] -= min(a[i + 1], b);
    }
    cout << ans << endl;

    return 0;
}