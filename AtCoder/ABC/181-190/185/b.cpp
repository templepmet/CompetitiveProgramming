#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int n, m, t, a, b, v, p = 0;
    bool f = false;
    cin >> n >> m >> t;
    v = n;
    while (m--) {
        cin >> a >> b;
        v -= (a - p);
        if (v <= 0) {
            f = true;
        }
        v += (b - a);
        v = min(v, n);
        p = b;
    }
    v -= (t - p);
    if (v <= 0) {
        f = true;
    }

    if (f) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }

    return 0;
}