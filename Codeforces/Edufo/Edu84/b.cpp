#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

int a[100001];
int b[100001];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, g;
        cin >> n;
        fill(a, a + n + 1, 0);
        fill(b, b + n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> k;
            while (k--) {
                cin >> g;
                if (a[i])
                    continue;
                if (b[g])
                    continue;
                a[i] = 1;
                b[g] = 1;
            }
        }
        int aa = 0, bb = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 0) {
                aa = i;
                break;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (b[i] == 0) {
                bb = i;
                break;
            }
        }
        if (aa == 0 || bb == 0) {
            cout << "OPTIMAL" << endl;
        }
        else {
            cout << "IMPROVE" << endl;
            cout << aa << " " << bb << endl;
        }
    }

    return 0;
}