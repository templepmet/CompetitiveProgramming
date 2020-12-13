#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int a, b, c, d, ans;
    cin >> a >> b >> c >> d;
    if (a == c && b == d) {
        ans = 0;
    }
    else if (a + b == c + d || a - b == c - d || abs(a - c) + abs(b - d) <= 3) {
        ans = 1;
    }
    else if ((a + b) % 2 == (c + d) % 2 || abs(a - c) + abs(b - d) <= 6) {
        ans = 2;
    }
    else {
        bool f = false;
        for (int i = -3; i <= 3; ++i) {
            for (int j = -3; j <= 3; ++j) {
                int x = c + i;
                int y = d + j;
                if (abs(c - x) + abs(d - y) > 3) continue;
                if (a + b == x + y || a - b == x - y) {
                    f = true;
                }
            }
        }
        if (f) {
            ans = 2;
        }
        else {
            ans = 3;
        }
    }
    cout << ans << endl;

    return 0;
}