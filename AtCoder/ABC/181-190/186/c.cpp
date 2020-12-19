#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int n, ans = 0;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        bool f = true;
        int t = i;
        while (t > 0) {
            if (t % 10 == 7) {
                f = false;
            }
            t /= 10;
        }
        t = i;
        while (t > 0) {
            if (t % 8 == 7) {
                f = false;
            }
            t /= 8;
        }
        if (f) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}