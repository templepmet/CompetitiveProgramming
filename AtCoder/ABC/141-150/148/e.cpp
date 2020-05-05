#include <iostream>

using namespace std;

int main() {
    long long n, ans = 0;
    cin >> n;
    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    n /= 2;
    while (n > 0) {
        ans += n / 5;
        n /= 5;
    }
    cout << ans << endl;

    return 0;
}