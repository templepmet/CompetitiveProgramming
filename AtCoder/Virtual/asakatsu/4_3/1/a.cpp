#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, a, ans = INF;
    cin >> n;
    while (n--) {
        cin >> a;
        ans = min(ans, a);
    }
    cout << ans << endl;

    return 0;
}