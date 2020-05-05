#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long long n, ans = 1e12;
    cin >> n;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            ans = min(ans, i + n / i);
        }
    }
    cout << ans - 2 << endl;

    return 0;
}