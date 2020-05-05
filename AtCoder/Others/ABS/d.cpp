#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, a, ans = INF, cnt;
    cin >> n;
    while (n--) {
        cin >> a;
        cnt = 0;
        while (a > 0 && a % 2 == 0) {
            a /= 2;
            cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}