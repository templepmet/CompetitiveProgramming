#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d = log10(i) + 1;
        if (d % 2) ans++;
    }
    cout << ans << endl;

    return 0;
}