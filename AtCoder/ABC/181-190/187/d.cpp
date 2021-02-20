#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int n, a, b;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    ll sumab = 0, alla = 0, suma = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        alla += a;
        v[i] = make_pair(a + b, a);
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto [ab, a] = v[i];
        sumab += ab;
        suma += a;
        ans++;
        if (sumab > alla - suma) {
            break;
        }
    }
    cout << ans << endl;

    return 0;
}