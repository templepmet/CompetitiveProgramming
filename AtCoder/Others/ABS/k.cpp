#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, t, x, y, bt = 0, bx = 0, by = 0;
    bool f = true;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t >> x >> y;
        int d = (t - bt) - (abs(x - bx) + abs(y - by));
        if (d < 0 || d % 2 != 0) {
            f = false;
        }
        bt = t; bx = x; by = y;
    }
    cout << (f ? "Yes" : "No") << endl;

    return 0;
}