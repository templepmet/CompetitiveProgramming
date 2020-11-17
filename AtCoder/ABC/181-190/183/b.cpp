#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    double x = sx - sy * (gx - sx) / (-gy - sy);
    cout << fixed << setprecision(10);
    cout << x << endl;

    return 0;
}