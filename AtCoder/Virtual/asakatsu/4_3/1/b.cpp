#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int m, n, nn, ans = 0, a = 0, b = 0;
    cin >> m >> n >> a;
    while (a > 0) {
        ans += a;
        a += b;
        b = a % m;
        a = (a / m) * n;
    }
    cout << ans << endl;

    return 0;
}

// 再利用されなかった鉛筆を再利用後の鉛筆に足す
// 再生産数が0で終了