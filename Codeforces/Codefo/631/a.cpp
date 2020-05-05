#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, a, d[1001] = {};
        cin >> n >> x;
        while (n--) {
            cin >> a;
            d[a] = 1;
        }
        for (int i = 0; i < x; ++i) {
            for (int j = 1; ; ++j) {
                if (d[j] == 0) {
                    d[j] = 1;
                    break;
                }
            }
        }
        for (int j = 1; ; ++j) {
            if (d[j] == 0) {
                cout << j - 1 << endl;
                break;
            }
        }
    }

    return 0;
}