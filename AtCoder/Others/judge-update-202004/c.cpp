#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int a, b, c, n, d[9];
    cin >> a >> b >> c;
    n = a + b + c;
    for (int i = 0; i < n; ++i) {
        d[i] = i + 1;
    }
    int m = min(a, min(b, c));

    int cnt = 0;
    do {
        int t[3][3] = { 0 };
        for (int i = 0; i < a; ++i)
            t[0][i] = d[i];
        for (int i = 0; i < b; ++i)
            t[1][i] = d[a + i];
        for (int i = 0; i < c; ++i)
            t[2][i] = d[a + b + i];
        
        bool f = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (j + 1 < 3 && t[i][j] < t[i][j + 1])
                    f = false;
                if (i + 1 < 3 && t[i][j] < t[i + 1][j])
                    f = false;
            }
        }
        if (f) {
            cnt++;
        }
    } while (next_permutation(d, d + n));

    cout << cnt << endl;

    return 0;
}