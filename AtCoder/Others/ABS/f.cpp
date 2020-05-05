#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, a, b, ans = 0;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        int num = i, sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if (a <= sum && sum <= b)
            ans += i;
    }
    cout << ans << endl;

    return 0;
}