#include <iostream>

using namespace std;

#define MOD 1000000007

using ull = unsigned long long;

ull a[(int)3e5];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ull ans = 0;
    for (int i = 0; i <= 60; ++i) {
        ull c0 = 0, c1 = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] & ((ull)1 << i))
                c1++;
            else
                c0++;
        }
        ans += (((c0 * c1) % MOD) * (((ull)1 << i) % MOD) % MOD);
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}