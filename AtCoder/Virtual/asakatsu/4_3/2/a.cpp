#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, ans = 0;
    string a, b, c;
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        if (a[i] == b[i])
            cnt++;
        if (b[i] == c[i])
            cnt++;
        if (c[i] == a[i])
            cnt++;
        if (cnt == 1)
            ans += 1;
        if (cnt == 0)
            ans += 2;
    }
    cout << ans << endl;

    return 0;
}