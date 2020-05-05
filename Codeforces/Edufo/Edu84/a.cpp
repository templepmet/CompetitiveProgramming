#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        if (n % 2 != k % 2) {
            cout << "NO" << endl;
        }
        else {
            if (k * (2 + (k - 1) * 2) / 2 > n) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}