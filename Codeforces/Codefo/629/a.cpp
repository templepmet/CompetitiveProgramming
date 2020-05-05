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
        int a, b;
        cin >> a >> b;
        if (a % b == 0) {
            cout << 0 << endl;
        }
        else {
            cout << (a / b + 1) * b - a << endl;
        }
    }

    return 0;
}