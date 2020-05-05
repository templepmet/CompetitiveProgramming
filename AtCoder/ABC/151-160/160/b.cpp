#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int x, ans = 0;
    cin >> x;
    ans += (x / 500) * 1000;
    x %= 500;
    ans += (x / 5) * 5;
    cout << ans << endl;

    return 0;
}