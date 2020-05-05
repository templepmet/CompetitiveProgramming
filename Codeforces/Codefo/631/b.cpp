#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int n, a[200000];
int b[200001];
int c[200001];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        fill(b, b + n + 1, 0);
        fill(c, c + n + 1, 0);
        int minv = INF, maxv = 0;
        for (int i = 0; i < n; ++i) {
            if (c[a[i]]) {
                break;
            }
            c[a[i]] = 1;
            minv = min(minv, a[i]);
            maxv = max(maxv, a[i]);
            if (minv == 1 && maxv == i + 1) {
                b[i + 1]++;
            }
        }
        minv = INF, maxv = 0;
        fill(c, c + n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            if (c[a[i]])
                break;
            c[a[i]] = 1;
            minv = min(minv, a[i]);
            maxv = max(maxv, a[i]);
            if (minv == 1 && maxv == n - i) {
                b[i]++;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (b[i] == 2) {
                cnt++;
            }
        }
        cout << cnt << endl;
        for (int i = 1; i <= n; ++i) {
            if (b[i] == 2) {
                cout << i << " " << n - i << endl;
            }
        }
    }

    return 0;
}