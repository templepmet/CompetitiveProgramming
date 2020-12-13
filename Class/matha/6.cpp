#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int n = 4500;
    double m = 1e8;
    double ans = 1;

    for (int i = 0; i < n; ++i) {
        ans *= (m - i) / m;
    }
    cout << ans << endl;

    return 0;
}