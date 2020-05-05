#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int a, b, k, cnt = 0;
    cin >> a >> b >> k;
    for (int i = min(a, b); i >= 0; --i) {
        if (a % i == 0 && b % i == 0) {
            cnt++;
            if (cnt == k) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}