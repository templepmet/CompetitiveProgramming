#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int n;
    ll a, b;
    cin >> n;
    ll sum = 0, suma = 0, alla = 0;
    vector<tuple<ll, ll, ll>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        alla += a;
        v[i] = make_tuple(2 * a + b, a, b);
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto [p, a, b] = v[i];
        sum += a + b;
        suma += a;
        ans++;
        if (sum > alla - suma) {
            break;
        }
    }
    cout << ans << endl;

    return 0;
}